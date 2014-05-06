/*
 * Copyright (C) 2013 Cloudius Systems, Ltd.
 *
 * This work is open source software, licensed under the terms of the
 * BSD license as described in the LICENSE file in the top-level directory.
 */


#include <sys/cdefs.h>

#include "drivers/virtio.hh"
#include "drivers/virtio-net.hh"
#include "drivers/pci-device.hh"
#include "interrupt.hh"

#include "mempool.hh"
#include "mmu.hh"

#include <string>
#include <string.h>
#include <map>
#include <errno.h>
#include <osv/debug.h>

#include "sched.hh"
#include "irqlock.hh"
#include "osv/trace.hh"

#include "drivers/clock.hh"
#include "drivers/clockevent.hh"

#include <osv/device.h>
#include <osv/ioctl.h>
#include <bsd/sys/net/ethernet.h>
#include <bsd/sys/net/if_types.h>
#include <bsd/sys/sys/param.h>

#include <bsd/sys/net/ethernet.h>
#include <bsd/sys/net/if_vlan_var.h>
#include <bsd/sys/netinet/in.h>
#include <bsd/sys/netinet/ip.h>
#include <bsd/sys/netinet/udp.h>
#include <bsd/sys/netinet/tcp.h>

#include "dde-net.h"
#include <linux/skbuff.h>

TRACEPOINT(trace_virtio_net_rx_packet, "if=%d, len=%d", int, int);
TRACEPOINT(trace_virtio_net_rx_wake, "");
TRACEPOINT(trace_virtio_net_fill_rx_ring, "if=%d", int);
TRACEPOINT(trace_virtio_net_fill_rx_ring_added, "if=%d, added=%d", int, int);
TRACEPOINT(trace_virtio_net_tx_packet, "if=%d, len=%d", int, int);
TRACEPOINT(trace_virtio_net_tx_failed_add_buf, "if=%d", int);
TRACEPOINT(trace_virtio_net_tx_no_space_calling_gc, "if=%d", int);
using namespace memory;

// TODO list
// irq thread affinity and tx affinity
// tx zero copy
// vlans?

namespace virtio {

int net::_instance = 0;

static void *registered_netdev = 0;
static net *nic = 0;

#define net_tag "virtio-net"
#define net_d(...)   tprintf_d(net_tag, __VA_ARGS__)
#define net_i(...)   tprintf_i(net_tag, __VA_ARGS__)
#define net_w(...)   tprintf_w(net_tag, __VA_ARGS__)
#define net_e(...)   tprintf_e(net_tag, __VA_ARGS__)

static void
req_list_add(struct sk_buff *req, struct sk_buff *&head) {
    if (head == 0) {
        head = req;
        req->prev = req->next = req;
    } else {
        req->prev = head->prev;
        req->next = head;
        req->prev->next = req->next->prev = req;
    }
}

static void
req_list_remove(struct sk_buff *req, struct sk_buff *&head) {
    req->prev->next = req->next;
    req->next->prev = req->prev;

    if (head == req)
        head = req->next;
    if (head == req)
        head = 0;
}

net *net::current_nic() {
    return nic ? nic : reinterpret_cast<net *>(current);
}

static int if_ioctl(struct ifnet *ifp, u_long command, caddr_t data)
{
    net *vnet = (net*)ifp->if_softc;
    void *netdev = vnet->netdev;
    int error = 0;
    switch(command) {
    case SIOCSIFMTU:
        net_d("SIOCSIFMTU");
        break;
    case SIOCSIFFLAGS:
        net_d("SIOCSIFFLAGS");
        /* Change status ifup, ifdown */
        if (ifp->if_flags & IFF_UP) {
            ifp->if_drv_flags |= IFF_DRV_RUNNING;
            dde_open_netdev(netdev);
            net_d("if_up");
        } else {
            ifp->if_drv_flags &= ~IFF_DRV_RUNNING;
            dde_close_netdev(netdev);
            net_d("if_down");
        }
        break;
    case SIOCADDMULTI:
    case SIOCDELMULTI:
        net_d("SIOCDELMULTI");
        break;
    default:
        net_d("redirecting to ether_ioctl()...");
        error = ether_ioctl(ifp, command, data);
        break;
    }

    return error;
}

static void if_qflush(struct ifnet *ifp)
{
    net_e("%s called, not implemented", __func__);
}

static int if_transmit(struct ifnet* ifp, struct mbuf* m_head)
{
    net *vnet = (net*)ifp->if_softc;
    void *netdev = vnet->netdev;
    return dde_xmit_packet(netdev, m_head);
}

static void if_init(void* xsc)
{
    /* Nothing to be done here */
}

static void if_getinfo(struct ifnet* ifp, struct if_data* out_data)
{
    net_e("%s called, not implemented", __func__);
}

struct ifnet *net::add_nic(void *netdev)
{
    registered_netdev = netdev;
    return 0;
}

net::net(pci::device& dev)
    : virtio_driver(dev), _rx_head(0)
{
    net_i("virtio net driver loaded");
    _driver_name = "virtio-net";

    if (registered_netdev) {
        _id = _instance++;
        this->netdev = registered_netdev;

        _ifn = if_alloc(IFT_ETHER);
        if (_ifn == NULL) {
            net_e("if_alloc failed!");
            return;
        }

        if_initname(_ifn, "eth", _id);
        _ifn->if_mtu = ETHERMTU;
        _ifn->if_softc = static_cast<void*>(this);
        _ifn->if_flags = IFF_BROADCAST /*| IFF_MULTICAST*/;
        _ifn->if_ioctl = if_ioctl;
        _ifn->if_transmit = if_transmit;
        _ifn->if_qflush = if_qflush;
        _ifn->if_init = if_init;
        _ifn->if_getinfo = if_getinfo;
        /* hard code for linux virtio driver */
        IFQ_SET_MAXLEN(&_ifn->if_snd, 256);

        _ifn->if_capabilities = 0;
        if (_csum) {
            _ifn->if_capabilities |= IFCAP_TXCSUM;
            if (_host_tso4) {
                _ifn->if_capabilities |= IFCAP_TSO4;
                _ifn->if_hwassist = CSUM_TCP | CSUM_UDP | CSUM_TSO;
            }
        }

        if (_guest_csum) {
            _ifn->if_capabilities |= IFCAP_RXCSUM;
            if (_guest_tso4)
                _ifn->if_capabilities |= IFCAP_LRO;
        }

        _ifn->if_capenable = _ifn->if_capabilities | IFCAP_HWSTATS;

        rx_thread = new sched::thread([this] { this->receiver(); });
        rx_thread->start();

        nic = this;
        ether_ifattach(_ifn, _config.mac);

        registered_netdev = 0;
    }
}

net::~net()
{
}

bool net::read_config()
{
    net_e("%s called, not implemented", __func__);
    return true;
}

/**
 * Original comment from FreeBSD
 * Alternative method of doing receive checksum offloading. Rather
 * than parsing the received frame down to the IP header, use the
 * csum_offset to determine which CSUM_* flags are appropriate. We
 * can get by with doing this only because the checksum offsets are
 * unique for the things we care about.
 *
 * @return true if csum is bad and false if csum is ok (!!!)
 */
bool net::bad_rx_csum(struct mbuf *m, struct net_hdr *hdr)
{
    net_e("%s called, not implemented", __func__);
    return false;
}

extern "C" {
    void __free_pages(struct page *p, unsigned int order);
}
void net::receiver()
{
    struct sk_buff *skb = 0;
    while (1) {
        sched::thread::wait_until([this] {
                bool empty;
                irq_save_lock_type irq_lock;
                WITH_LOCK(irq_lock) {
                    sched::preempt_disable();
                    WITH_LOCK(_rx_lock) {
                        empty = (this->_rx_head == 0);
                    }
                    sched::preempt_enable();
                }
                return !empty;
            });

        while ((skb = _rx_head) != 0) {
            irq_save_lock_type irq_lock;
            WITH_LOCK(irq_lock) {
                sched::preempt_disable();
                WITH_LOCK(_rx_lock) {
                    req_list_remove(skb, _rx_head);
                }
                sched::preempt_enable();
            }

            struct mbuf *m = m_getjcl(M_NOWAIT, MT_DATA, M_PKTHDR, MCLBYTES);
            int len = skb->tail - skb->data;

            memcpy(m->m_hdr.mh_data, skb->data, len);

            if (skb_shinfo(skb)->nr_frags) {
                int i;
                for (i = 0; i < skb_shinfo(skb)->nr_frags; i ++) {
                    skb_frag_t *frag = skb_shinfo(skb)->frags + i;
                    memcpy(m->m_hdr.mh_data + len, page_address(frag->page) + frag->page_offset, frag->size);
                    len += frag->size;
                    __free_pages(frag->page, 0);
                }
            }
            m->M_dat.MH.MH_pkthdr.len = m->m_hdr.mh_len = len;
            m->M_dat.MH.MH_pkthdr.rcvif = _ifn;
            m->M_dat.MH.MH_pkthdr.csum_flags = 0;
            // kprintf("RX: %d bytes\n", len);

            (*_ifn->if_input)(_ifn, m);

            free(skb->data);
            free(skb);
        }
    }
}

void net::fill_rx_ring()
{
    net_e("%s called, not implemented", __func__);
}

// TODO: Does it really have to be "locked"?
int net::tx_locked(struct mbuf *m_head, bool flush)
{
    net_e("%s called, not implemented", __func__);
    return 0;
}

struct mbuf*
net::tx_offload(struct mbuf* m, struct net_hdr* hdr)
{
    net_e("%s called, not implemented", __func__);
    return 0;
}

void net::tx_gc()
{
    net_e("%s called, not implemented", __func__);
}

void net::rx(struct sk_buff *skb)
{
    _rx_lock.lock();
    req_list_add(skb, _rx_head);
    _rx_lock.unlock();

    rx_thread->wake();
}

u32 net::get_driver_features(void)
{
    net_e("%s called, not implemented", __func__);
    return 0;
}

hw_driver* net::probe(hw_device* dev)
{
    return virtio::probe<net, VIRTIO_NET_DEVICE_ID>(dev);
}

}

#include "dde.h"
#include "dde-net.h"

#include <sys/mbuf.h>
#include <net/if_var.h>

#include <linux/etherdevice.h>
#include <linux/list.h>
#include <linux/slab.h>
#include <linux/if_ether.h>
#include <linux/scatterlist.h>
#include <linux/skbuff.h>

const int SKB_HEAD_ROOM = 0;
const int SKB_IP_ALIGN = 2;

struct net_device *alloc_etherdev_mqs(int sizeof_priv, unsigned int txqs, unsigned int rxqs) {
    struct net_device *netdev;
    void *priv = 0;

    netdev = (struct net_device *)kzalloc(sizeof(struct net_device), GFP_KERNEL);
    if (netdev == 0)
        goto error_alloc_netdev;

    netdev->addr_len = ETH_ALEN;
    netdev->dev_addr = (unsigned char *)kzalloc(ETH_ALEN, GFP_KERNEL);
    if (netdev->dev_addr == 0)
        goto error_alloc_addr;

    priv = kzalloc(sizeof_priv, GFP_KERNEL);
    if (priv == 0)
        goto error_alloc_priv;

    netdev->priv = priv;
    INIT_LIST_HEAD(&netdev->uc.list);
    netdev->uc.count = 0;
    INIT_LIST_HEAD(&netdev->mc.list);
    netdev->mc.count = 0;

	return netdev;

error_alloc_priv:
    kfree(netdev->dev_addr);
error_alloc_addr:
    kfree(netdev);
error_alloc_netdev:
    return 0;
}

void *netdev_priv(const struct net_device *netdev) {
    return netdev->priv;
}

int register_netdev(struct net_device *netdev) {
    netdev->ifn = dde_add_nic(netdev, netdev->hw_features, netdev->dev_addr);
	return 0;
}

void netif_napi_add(struct net_device *dev, struct napi_struct *napi, int (*poll)(struct napi_struct *, int), int weight) {
    napi->poll = poll;
    napi->weight = weight;
    dev->napi = napi;
}

int napi_schedule_prep(struct napi_struct *napi) {
    napi->done = 0;
	return 1;
}
void __napi_schedule(struct napi_struct *napi) {
    while (!napi->done) {
        napi->poll(napi, napi->weight);
    }
}

void napi_schedule(struct napi_struct *napi) {
	__napi_schedule(napi);
}

void napi_complete(struct napi_struct *napi) {
    napi->done = 1;
}

static struct sk_buff *alloc_skb(unsigned int length) {
    struct sk_buff *skb;
    int size = (length + SKB_HEAD_ROOM + 3) & ~(0x3);

    skb = kzalloc(sizeof(struct sk_buff), GFP_KERNEL);
    if (skb == 0)
        goto error_alloc_skb;
    skb->head = (unsigned char *)kzalloc(size + sizeof(struct skb_shared_info), GFP_KERNEL);
    if (skb->head == 0)
        goto error_alloc_data;

    skb->tail = skb->data = skb->head;
    skb->end = skb->head + length;
    skb->truesize = size;

    return skb;

error_alloc_data:
    kfree(skb);
error_alloc_skb:
	return 0;
}

struct sk_buff *netdev_alloc_skb_ip_align(struct net_device *netdev, unsigned int length) {
    struct sk_buff *skb = alloc_skb(length + SKB_IP_ALIGN);
    if (skb) {
        skb->dev = netdev;
        skb->data += SKB_IP_ALIGN;
        skb->tail += SKB_IP_ALIGN;
    }
    return skb;
}

void dev_kfree_skb_any(struct sk_buff *skb) {
    kfree(skb->head);
    kfree(skb);
}

unsigned int skb_headlen(const struct sk_buff *skb) {
	return skb->len - skb->data_len;
}

int skb_tailroom(const struct sk_buff *skb) {
	return skb->end - skb->tail;
}

unsigned char *skb_end_pointer(const struct sk_buff *skb) {
	return skb->end;
}

unsigned char *skb_put(struct sk_buff *skb, unsigned int len) {
    unsigned char *tmp = skb->tail;
    skb->tail += len;
    skb->len += len;
    if (skb->tail > skb->end) {
        printk("no enough size!!\n");
        /* This should trigger a pgfault */
        return 0;
    }
    return tmp;
}

int skb_to_sgvec(struct sk_buff *skb, struct scatterlist *sg, int offset, int len) {
    sg_set_buf(sg, skb->data, skb->len);
	return 1;
}

void __skb_fill_page_desc(struct sk_buff *skb, int i, struct page *p, int off, int size) {
    skb_frag_t *frag = skb_shinfo(skb)->frags + i;
    frag->page  = p;
    frag->page_offset = off;
    frag->size = size;
}

int netif_receive_skb(struct sk_buff *skb) {
    dde_recv(skb);
	return 0;
}


int dde_open_netdev(void *dev) {
    struct net_device *netdev = (struct net_device *)dev;
    return netdev->netdev_ops->ndo_open(netdev);
}

int dde_close_netdev(void *dev) {
    struct net_device *netdev = (struct net_device *)dev;
    return netdev->netdev_ops->ndo_stop(netdev);
}

int dde_xmit_packet(void *dev, struct mbuf *m_head) {
    struct net_device *netdev = (struct net_device *)dev;
    struct sk_buff *skb;
    netdev_tx_t result;
    int len = 0;
    struct mbuf *m;

    for (m = m_head; m != 0; m = m->m_hdr.mh_next)
        len += m->m_hdr.mh_len;

    skb = netdev_alloc_skb_ip_align(netdev, len);
    if (skb == 0)
        goto error_alloc_skb;

    for (m = m_head; m != 0; m = m->m_hdr.mh_next) {
        /* printk("TX frag len=%d\n", m->m_hdr.mh_len); */
        /* dump_buf((unsigned char *)m->m_hdr.mh_data, m->m_hdr.mh_len); */
        memcpy(skb->data + skb->len, (void *)m->m_hdr.mh_data, m->m_hdr.mh_len);
        skb->tail += m->m_hdr.mh_len;
        skb->len += m->m_hdr.mh_len;
        /* XXX what to do w/ data_len? */
        skb->data_len += m->m_hdr.mh_len;
    }

    /* printk("TX: %d bytes\n", len); */

    result = netdev->netdev_ops->ndo_start_xmit(skb, netdev);

    m_freem(m_head);
    return result;

error_alloc_skb:
    return -ENOMEM;
}

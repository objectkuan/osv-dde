#include "dde-net.h"

#include <sys/mbuf.h>

#include "drivers/virtio-net.hh"

/* copied from linux header as we cannot include them directly... */
enum {SKB_GSO_TCPV4 = 1, SKB_GSO_UDP = 2, SKB_GSO_DODGY = 4, SKB_GSO_TCP_ECN = 8, SKB_GSO_TCPV6 = 16, SKB_GSO_FCOE = 32, };
/*1011*/ #define NETIF_F_SG 1
/*1014*/ #define NETIF_F_HW_CSUM 8
/*1016*/ #define NETIF_F_HIGHDMA 32
/*1017*/ #define NETIF_F_FRAGLIST 64
/*1020*/ #define NETIF_F_HW_VLAN_FILTER 512
/*1040*/ #define NETIF_F_GSO_SHIFT 16
/*1042*/ #define NETIF_F_TSO (SKB_GSO_TCPV4 << NETIF_F_GSO_SHIFT)
/*1043*/ #define NETIF_F_UFO (SKB_GSO_UDP << NETIF_F_GSO_SHIFT)
/*1045*/ #define NETIF_F_TSO_ECN (SKB_GSO_TCP_ECN << NETIF_F_GSO_SHIFT)
/*1046*/ #define NETIF_F_TSO6 (SKB_GSO_TCPV6 << NETIF_F_GSO_SHIFT)
/*1065*/ #define NETIF_F_ALL_TSO (NETIF_F_TSO | NETIF_F_TSO6 | NETIF_F_TSO_ECN)

struct ifnet *dde_add_nic(void *netdev, unsigned long hw_features, unsigned char *mac) {
    virtio::net *nic = virtio::net::current_nic();

    memcpy(nic->_config.mac, mac, 6);

    /* features */
    if (hw_features & NETIF_F_HW_CSUM)
        nic->_csum = true;
    if (hw_features & NETIF_F_TSO)
        nic->_host_tso4 = true;
    if (hw_features & NETIF_F_TSO_ECN)
        nic->_host_tso_ecn = true;
    nic->_guest_csum = true;
    nic->_guest_tso4 = true;
    nic->_guest_ufo = true;
    nic->_status = true;
    nic->_mergeable_bufs = true;
    nic->_tso_ecn = true;

    return nic->add_nic(netdev);
}

void dde_recv(struct sk_buff *skb) {
    virtio::net *nic = virtio::net::current_nic();
    nic->rx(skb);
}

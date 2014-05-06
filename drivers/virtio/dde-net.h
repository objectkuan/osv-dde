#ifndef DDE_NET_H
#define DDE_NET_H

#ifdef __cplusplus
extern "C" {
#endif

struct sk_buff;
struct mbuf;
struct ifnet;

struct ifnet *dde_add_nic(void *netdev, unsigned long hw_features, unsigned char *mac);
int dde_open_netdev(void *netdev);
int dde_close_netdev(void *netdev);
int dde_xmit_packet(void *netdev, struct mbuf *data);
void dde_recv(struct sk_buff *skb);

#ifdef __cplusplus
}
#endif

#endif /* ! DDE_NET_H */

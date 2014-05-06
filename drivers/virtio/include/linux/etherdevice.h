#ifndef __LINUX_ETHERDEVICE_H__
#define __LINUX_ETHERDEVICE_H__

/*0*/ #include <linux/types.h>
/*27*/ #include <linux/if_ether.h>
/*28*/ #include <linux/netdevice.h>
/*33*/ __be16 eth_type_trans(struct sk_buff * a, struct net_device * b);
/*45*/ int eth_mac_addr(struct net_device * a, void * b);
/*47*/ int eth_validate_addr(struct net_device * a);
/*52*/ struct net_device * alloc_etherdev_mqs(int a, unsigned int b, unsigned int c);
/*53*/ #define alloc_etherdev(sizeof_priv) alloc_etherdev_mq(sizeof_priv, 1)
/*54*/ #define alloc_etherdev_mq(sizeof_priv,count) alloc_etherdev_mqs(sizeof_priv, count, count)
/*140*/ void random_ether_addr(u8 * a);

#endif

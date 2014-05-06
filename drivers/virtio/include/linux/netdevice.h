#ifndef __LINUX_NETDEVICE_H__
#define __LINUX_NETDEVICE_H__

/*0*/ struct net_device;
/*0*/ #include <linux/netdevice.h>
/*0*/ struct net_device_stats;
/*0*/ struct netdev_hw_addr_list;
/*28*/ #include <linux/if.h>
/*29*/ #include <linux/if_ether.h>
/*31*/ #include <linux/if_link.h>
/*35*/ #include <linux/timer.h>
/*36*/ #include <linux/delay.h>
/*38*/ #include <asm/cache.h>
/*41*/ #include <linux/device.h>
/*42*/ #include <linux/percpu.h>
/*45*/ #include <linux/workqueue.h>
/*47*/ #include <linux/ethtool.h>
/*60*/ #define SET_ETHTOOL_OPS(netdev,ops) ( (netdev)->ethtool_ops = (ops) )
/*110*/ enum netdev_tx {__NETDEV_TX_MIN = -2147483648, NETDEV_TX_OK = 0, NETDEV_TX_BUSY = 16, NETDEV_TX_LOCKED = 32, };;
/*111*/ typedef enum netdev_tx netdev_tx_t;
/**194**/ struct net_device_stats {
	unsigned long rx_length_errors;
	unsigned long rx_dropped;
	unsigned long rx_frame_errors;
	unsigned long tx_fifo_errors;
	unsigned long tx_dropped;
};
/*213*/ #include <linux/skbuff.h>
/**232**/ struct netdev_hw_addr {
	struct list_head list;
	unsigned char addr[32];
};
/**237**/ struct netdev_hw_addr_list {
	int count;
	struct list_head list;
};
/*239*/ #define netdev_hw_addr_list_count(l) ((l)->count)
/*241*/ #define netdev_hw_addr_list_for_each(ha,l) list_for_each_entry(ha, &(l)->list, list)
/*244*/ #define netdev_uc_count(dev) netdev_hw_addr_list_count(&(dev)->uc)
/*246*/ #define netdev_for_each_uc_addr(ha,dev) netdev_hw_addr_list_for_each(ha, &(dev)->uc)
/*249*/ #define netdev_mc_count(dev) netdev_hw_addr_list_count(&(dev)->mc)
/*251*/ #define netdev_for_each_mc_addr(ha,dev) netdev_hw_addr_list_for_each(ha, &(dev)->mc)
/**350**/ struct napi_struct {
    int (*poll)(struct napi_struct *, int);
    int weight;
    volatile int done;
};
/*414*/ typedef enum rx_handler_result rx_handler_result_t;
/*417*/ void __napi_schedule(struct napi_struct * a);
/*437*/ int napi_schedule_prep(struct napi_struct * a);
/*450*/ void napi_schedule(struct napi_struct * a);
/*469*/ void napi_complete(struct napi_struct * a);
/*484*/ void napi_disable(struct napi_struct * a);
/*498*/ void napi_enable(struct napi_struct * a);
/**951**/ struct net_device_ops {
	int (*ndo_open)(struct net_device *);
	int (*ndo_stop)(struct net_device *);
	netdev_tx_t (*ndo_start_xmit)(struct sk_buff *, struct net_device *);
	int (*ndo_validate_addr)(struct net_device *);
	int (*ndo_set_mac_address)(struct net_device *, void *);
	void (*ndo_set_rx_mode)(struct net_device *);
	int (*ndo_change_mtu)(struct net_device *, int);
	struct rtnl_link_stats64 *(*ndo_get_stats64)(struct net_device *, struct rtnl_link_stats64 *);
	void (*ndo_vlan_rx_add_vid)(struct net_device *, unsigned short);
	void (*ndo_vlan_rx_kill_vid)(struct net_device *, unsigned short);
	void (*ndo_poll_controller)(struct net_device *);
};
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
/**1320**/ struct net_device {
	union { void * ml_priv; struct pcpu_lstats * lstats; struct pcpu_tstats * tstats; struct pcpu_dstats * dstats; };
	char name[16];
	struct net_device_stats stats;
	struct device dev;
	unsigned char * dev_addr;
	unsigned char addr_len;
	unsigned int flags;
	struct netdev_hw_addr_list uc;
	struct netdev_hw_addr_list mc;
	unsigned int mtu;
	unsigned int priv_flags;
	const struct net_device_ops * netdev_ops;
	u32 features;
	u32 hw_features;
	const struct ethtool_ops * ethtool_ops;

    void *ifn;
    void *priv;
    struct napi_struct *napi;
};
/*1451*/ void * netdev_priv(const struct net_device * a);
/*1456*/ #define SET_NETDEV_DEV(net,pdev) ((net)->dev.parent = (pdev))
/*1475*/ void netif_napi_add(struct net_device * a, struct napi_struct * b, int (*c)(struct napi_struct *, int), int d);
/*1527*/ #include <linux/notifier.h>
/*1642*/ void free_netdev(struct net_device * a);
/*1812*/ void netif_start_queue(struct net_device * a);
/*1846*/ void netif_wake_queue(struct net_device * a);
/*1877*/ void netif_stop_queue(struct net_device * a);
/*2055*/ void dev_kfree_skb_any(struct sk_buff * a);
/*2059*/ int netif_receive_skb(struct sk_buff * a);
/*2159*/ void netif_carrier_on(struct net_device * a);
/*2161*/ void netif_carrier_off(struct net_device * a);
/*2449*/ int register_netdev(struct net_device * a);
/*2450*/ void unregister_netdev(struct net_device * a);

#endif

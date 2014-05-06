#ifndef __LINUX_ETHTOOL_H__
#define __LINUX_ETHTOOL_H__

/*19*/ #include <linux/types.h>
/*20*/ #include <linux/if_ether.h>
/**238**/ struct ethtool_ringparam {
	__u32 rx_max_pending;
	__u32 tx_max_pending;
	__u32 rx_pending;
	__u32 tx_pending;
};
/*752*/ u32 ethtool_op_get_link(struct net_device * a);
/**960**/ struct ethtool_ops {
	u32 (*get_link)(struct net_device *);
	void (*get_ringparam)(struct net_device *, struct ethtool_ringparam *);
};

#endif

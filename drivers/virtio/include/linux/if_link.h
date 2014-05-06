#ifndef __LINUX_IF_LINK_H__
#define __LINUX_IF_LINK_H__

/*4*/ #include <linux/types.h>
/**71**/ struct rtnl_link_stats64 {
	__u64 rx_dropped;
	__u64 rx_length_errors;
	__u64 rx_frame_errors;
	__u64 rx_packets;
	__u64 tx_packets;
	__u64 rx_bytes;
	__u64 tx_bytes;
	__u64 tx_dropped;
};

#endif

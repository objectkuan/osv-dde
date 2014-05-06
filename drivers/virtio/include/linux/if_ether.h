#ifndef __LINUX_IF_ETHER_H__
#define __LINUX_IF_ETHER_H__

/*24*/ #include <linux/types.h>
/*31*/ #define ETH_ALEN 6
/*32*/ #define ETH_HLEN 14
/*34*/ #define ETH_DATA_LEN 1500
/**130**/ struct ethhdr {
	unsigned char h_dest[6];
};
/*133*/ #include <linux/skbuff.h>

#endif

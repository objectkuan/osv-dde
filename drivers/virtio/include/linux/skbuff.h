#ifndef __LINUX_SKBUFF_H__
#define __LINUX_SKBUFF_H__

/*0*/ struct net_device;

#ifndef __cplusplus
/*0*/ #include <linux/types.h>
/*0*/ #include <linux/netdevice.h>
/*17*/ #include <linux/kernel.h>
/*25*/ #include <linux/spinlock.h>
/*26*/ #include <linux/net.h>
/*36*/ #define CHECKSUM_UNNECESSARY 1
/*38*/ #define CHECKSUM_PARTIAL 3
/*295*/ enum _home_enight_linux_322_include_linux_skbuffh_295 {SKB_GSO_TCPV4 = 1, SKB_GSO_UDP = 2, SKB_GSO_DODGY = 4, SKB_GSO_TCP_ECN = 8, SKB_GSO_TCPV6 = 16, SKB_GSO_FCOE = 32, };;
#else
typedef unsigned char __u8;
typedef unsigned short __u16;
typedef __u16 __be16;
typedef unsigned int __u32;
typedef __u32 __wsum;

struct page;
extern "C" {
void *lowmem_page_address(const struct page *p);
#define page_address(page) lowmem_page_address(page)
}
#endif

/*137*/ #define MAX_SKB_FRAGS (65536/PAGE_SIZE + 2)
typedef struct skb_frag_struct {
    struct page *page;
    __u32 page_offset;
    __u32 size;
} skb_frag_t;
/**259**/ struct skb_shared_info {
	unsigned short nr_frags;
	unsigned short gso_type;
	unsigned short gso_size;
	unsigned short gso_segs;
    skb_frag_t frags[MAX_SKB_FRAGS];
};
/**475**/ struct sk_buff {
	union { __wsum csum; struct { __u16 csum_start; __u16 csum_offset; }; };
	/* union { __u32 mark; __u32 dropcount; }; */
	char cb[48];
	unsigned int data_len;
	unsigned int len;
	unsigned int truesize;
	struct net_device * dev;
	__u8 ip_summed;
	__be16 protocol;
	__u8 pkt_type;
	unsigned char * data;
    unsigned char *head, *tail, *end;
    struct sk_buff *prev, *next;
};

#ifdef __cplusplus
extern "C" {
#endif
/*621*/ unsigned char * skb_end_pointer(const struct sk_buff * a);
/*630*/ #define skb_shinfo(SKB) ((struct skb_shared_info *)(skb_end_pointer(SKB)))
#ifdef __cplusplus
}
#endif

#ifndef __cplusplus
/*481*/ #include <linux/slab.h>
/*483*/ #include <asm/system.h>
/*538*/ void kfree_skb(struct sk_buff * a);
/*539*/ void consume_skb(struct sk_buff * a);
/*576*/ int skb_to_sgvec(struct sk_buff * a, struct scatterlist * b, int c, int d);
/*580*/ #define dev_kfree_skb(a) consume_skb(a)
/*1151*/ unsigned int skb_headlen(const struct sk_buff * a);
/*1183*/ void __skb_fill_page_desc(struct sk_buff * a, int b, struct page * c, int d, int e);
/*1250*/ unsigned char * skb_put(struct sk_buff * a, unsigned int b);
/*1326*/ int skb_tailroom(const struct sk_buff * a);
/*1459*/ int skb_checksum_start_offset(const struct sk_buff * a);
/*1541*/ void skb_trim(struct sk_buff * a, unsigned int b);
/*1585*/ void skb_orphan(struct sk_buff * a);
/*1662*/ struct sk_buff * netdev_alloc_skb_ip_align(struct net_device * a, unsigned int b);
/*2347*/ void nf_reset(struct sk_buff * a);
/*2448*/ int skb_is_gso(const struct sk_buff * a);
/*2493*/ bool skb_partial_csum_set(struct sk_buff * a, u16 b, u16 c);
#endif

#endif

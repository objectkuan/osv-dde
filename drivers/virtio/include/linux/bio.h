#ifndef __LINUX_BIO_H__
#define __LINUX_BIO_H__

/*0*/ struct bio;
/*23*/ #include <linux/highmem.h>
/*24*/ #include <linux/mempool.h>
/*29*/ #include <asm/io.h>
/*32*/ #include <linux/blk_types.h>
/*217*/ void bio_put(struct bio * a);
/*243*/ struct bio * bio_map_kern(struct request_queue * a, void * b, unsigned int c, gfp_t d);

#endif

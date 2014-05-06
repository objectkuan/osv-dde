#ifndef __LINUX_SCATTERLIST_H__
#define __LINUX_SCATTERLIST_H__

/*0*/ struct scatterlist;
/*0*/ #include <asm-generic/scatterlist.h>
/*0*/ #include <linux/types.h>
/*6*/ #include <linux/mm.h>
/*8*/ #include <asm/io.h>
/*113*/ void sg_set_buf(struct scatterlist * a, const void * b, unsigned int c);
/*118*/ #define for_each_sg(sglist,sg,nr,__i) for (__i = 0, sg = (sglist); __i < (nr); __i++, sg = sg_next(sg))
/*185*/ dma_addr_t sg_phys(struct scatterlist * a);
/*200*/ void * sg_virt(struct scatterlist * a);
/*202*/ struct scatterlist * sg_next(struct scatterlist * a);
/*204*/ void sg_init_table(struct scatterlist * a, unsigned int b);
/*205*/ void sg_init_one(struct scatterlist * a, const void * b, unsigned int c);

#endif

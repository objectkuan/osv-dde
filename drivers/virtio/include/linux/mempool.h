#ifndef __LINUX_MEMPOOL_H__
#define __LINUX_MEMPOOL_H__

/*7*/ #include <linux/wait.h>
/*24*/ typedef struct mempool_s mempool_t;
/*32*/ void mempool_destroy(mempool_t * a);
/*33*/ void * mempool_alloc(mempool_t * a, gfp_t b);
/*34*/ void mempool_free(void * a, mempool_t * b);
/*59*/ mempool_t * mempool_create_kmalloc_pool(int a, size_t b);

#endif

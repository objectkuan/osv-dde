#ifndef __LINUX_SLAB_H__
#define __LINUX_SLAB_H__

/*12*/ #include <linux/gfp.h>
/*13*/ #include <linux/types.h>
/*161*/ void kfree(const void * a);
/*185*/ #include <linux/slub_def.h>
/*341*/ void * kzalloc(size_t a, gfp_t b);

#endif

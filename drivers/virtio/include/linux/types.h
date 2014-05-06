#ifndef __LINUX_TYPES_H__
#define __LINUX_TYPES_H__

/*0*/ #include <asm/posix_types_64.h>
/*26*/ typedef __kernel_mode_t mode_t;
/*28*/ typedef __kernel_off_t off_t;
#ifndef __cplusplus
/*37*/ typedef _Bool bool;
#endif
/*53*/ typedef __kernel_loff_t loff_t;
/*62*/ typedef __kernel_size_t size_t;
/*67*/ typedef __kernel_ssize_t ssize_t;
/*141*/ typedef unsigned long sector_t;
/*154*/ typedef u64 dma_addr_t;
/*178*/ typedef __u16 __be16;
/*179*/ typedef __u32 __le32;
/*185*/ typedef __u32 __wsum;
/*201*/ typedef unsigned int gfp_t;
/*202*/ typedef unsigned int fmode_t;
/*205*/ typedef u64 phys_addr_t;
/*210*/ typedef phys_addr_t resource_size_t;
/*214*/ typedef struct atomic_t atomic_t;
/*214*/ struct atomic_t { int counter; };
/*219*/ typedef struct atomic64_t atomic64_t;
/*219*/ struct atomic64_t { long counter; };
/*224*/ struct list_head { struct list_head * next; struct list_head * prev; };

#endif

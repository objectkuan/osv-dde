#ifndef __LINUX_GFP_H__
#define __LINUX_GFP_H__

/*5*/ #include <linux/stddef.h>
/*14*/ #define ___GFP_HIGHMEM 0x02u
/*17*/ #define ___GFP_WAIT 0x10u
/*18*/ #define ___GFP_HIGH 0x20u
/*19*/ #define ___GFP_IO 0x40u
/*20*/ #define ___GFP_FS 0x80u
/*22*/ #define ___GFP_NOWARN 0x200u
/*25*/ #define ___GFP_NORETRY 0x1000u
/*27*/ #define ___GFP_ZERO 0x8000u
/*28*/ #define ___GFP_NOMEMALLOC 0x10000u
/*29*/ #define ___GFP_HARDWALL 0x20000u
/*50*/ #define __GFP_HIGHMEM ((__force gfp_t)___GFP_HIGHMEM)
/*69*/ #define __GFP_WAIT ((__force gfp_t)___GFP_WAIT)
/*70*/ #define __GFP_HIGH ((__force gfp_t)___GFP_HIGH)
/*71*/ #define __GFP_IO ((__force gfp_t)___GFP_IO)
/*72*/ #define __GFP_FS ((__force gfp_t)___GFP_FS)
/*74*/ #define __GFP_NOWARN ((__force gfp_t)___GFP_NOWARN)
/*77*/ #define __GFP_NORETRY ((__force gfp_t)___GFP_NORETRY)
/*79*/ #define __GFP_ZERO ((__force gfp_t)___GFP_ZERO)
/*80*/ #define __GFP_NOMEMALLOC ((__force gfp_t)___GFP_NOMEMALLOC)
/*81*/ #define __GFP_HARDWALL ((__force gfp_t)___GFP_HARDWALL)
/*101*/ #define GFP_ATOMIC (__GFP_HIGH)
/*104*/ #define GFP_KERNEL (__GFP_WAIT | __GFP_IO | __GFP_FS)
/*108*/ #define GFP_HIGHUSER (__GFP_WAIT | __GFP_IO | __GFP_FS | __GFP_HARDWALL | __GFP_HIGHMEM)
/*328*/ struct page * alloc_pages(gfp_t a, unsigned int b);
/*338*/ #define alloc_page(gfp_mask) alloc_pages(gfp_mask, 0)
/*347*/ void * alloc_pages_exact(size_t a, gfp_t b);
/*348*/ void free_pages_exact(void * a, size_t b);
/*358*/ void __free_pages(struct page * a, unsigned int b);
/*362*/ #define __free_page(page) __free_pages((page), 0)

#endif

#ifndef __ASM_PAGE_TYPES_H__
#define __ASM_PAGE_TYPES_H__

/*4*/ #include <linux/const.h>
/*5*/ #include <linux/types.h>
/*8*/ #define PAGE_SHIFT 12
/*9*/ #define PAGE_SIZE (_AC(1,UL) << PAGE_SHIFT)
/*37*/ #include <asm/page_64_types.h>

#endif

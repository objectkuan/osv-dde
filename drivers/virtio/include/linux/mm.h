#ifndef __LINUX_MM_H__
#define __LINUX_MM_H__

/*4*/ #include <linux/errno.h>
/*8*/ #include <linux/gfp.h>
/*9*/ #include <linux/list.h>
/*11*/ #include <linux/rbtree.h>
/*15*/ #include <linux/mm_types.h>
/*32*/ extern unsigned long totalram_pages;
/*44*/ #include <asm/processor.h>
/*49*/ #define PAGE_ALIGN(addr) ALIGN(addr, PAGE_SIZE)
/*734*/ #include <linux/vmstat.h>
/*739*/ void * lowmem_page_address(const struct page * a);
/*761*/ #define page_address(page) lowmem_page_address(page)
/*1333*/ void si_meminfo(struct sysinfo * a);

#endif

#ifndef __ASM_GENERIC_MEMORY_MODEL_H__
#define __ASM_GENERIC_MEMORY_MODEL_H__

/*51*/ #define __pfn_to_page(pfn) (vmemmap + (pfn))
/*52*/ #define __page_to_pfn(page) (unsigned long)((page) - vmemmap)
/*72*/ #define page_to_pfn __page_to_pfn
/*73*/ #define pfn_to_page __pfn_to_page

#endif

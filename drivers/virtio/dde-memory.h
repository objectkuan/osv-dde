#ifndef DDE_MEMORY_H
#define DDE_MEMORY_H

#ifdef __cplusplus
extern "C" {
#endif

void *dde_phys_to_virt(unsigned long phys);

void *dde_alloc_pages(int nr_page);
void dde_free_pages(void *addr);

#ifdef __cplusplus
}
#endif

#endif /* ! DDE_MEMORY_H */

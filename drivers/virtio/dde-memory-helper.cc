#include "dde-memory.h"

#include <mmu.hh>
#include <map>
#include <osv/pagealloc.hh>

void *dde_phys_to_virt(unsigned long phys) {
    return mmu::phys_to_virt(phys);
}

std::map<void *, int> allocated_pages;

void *dde_alloc_pages(int nr_page) {
    void *ret = memory::alloc_huge_page(nr_page << 12);
    if (ret)
        allocated_pages[ret] = nr_page;
    return ret;
}

void dde_free_pages(void *addr) {
    memory::free_huge_page(addr, allocated_pages[addr] << 12);
}

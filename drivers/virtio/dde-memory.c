#include <asm-generic/int-ll64.h>
#include <linux/types.h>
#include <linux/slab.h>
#include <linux/slub_def.h>
#include <linux/gfp.h>
#include <linux/mempool.h>

#include "dde.h"
#include "dde-memory.h"
#include "dde-pci.h"

#undef NULL

#include <api/stdlib.h>
#include <api/x86_64/bits/io.h>

/**
 * Address conversion
 */
void *phys_to_virt(phys_addr_t phys) {
	return dde_phys_to_virt(phys);
}

void *lowmem_page_address(const struct page *p) {
	return p->ptr;
}
/**
 * Allocator
 */

void *kmalloc(size_t a, gfp_t b) {
    return malloc(a);
}

void *kzalloc(size_t a, gfp_t b) {
	void *ret = malloc(a);
    if (ret)
        memset(ret, 0, a);
	return ret;
}

void kfree(const void * a) {
    void *ptr = (void *)a;
    free(ptr);
}

struct page *alloc_pages(gfp_t a, unsigned int order) {
    struct page *p = kzalloc(sizeof(struct page), GFP_KERNEL);
    if (p == 0)
        return 0;

    p->ptr = dde_alloc_pages(1 << order);
    if (p->ptr == 0) {
        kfree(p);
        return 0;
    }

	return p;
}

void __free_pages(struct page *page, unsigned int order) {
    dde_free_pages(page->ptr);
    kfree(page);
}

void *alloc_pages_exact(size_t a, gfp_t b) {
	return dde_alloc_pages(a);
}

void free_pages_exact(void *a, size_t b) {
    dde_free_pages(a);
}

#define MEMPOOL_PTR_BITS  0xCCCC0000UL
#define MEMPOOL_SIZE_MASK 0x0000FFFFUL

mempool_t *mempool_create_kmalloc_pool(int a, size_t size) {
    return (mempool_t *)(MEMPOOL_PTR_BITS | size);
}

void mempool_destroy(mempool_t *pool) {
}

void *mempool_alloc(mempool_t *pool, gfp_t b) {
    size_t size = ((size_t)pool) & MEMPOOL_SIZE_MASK;
	return kmalloc(size, b);
}

void mempool_free(void *ptr, mempool_t *pool) {
    kfree(ptr);
}

void *__alloc_percpu(size_t size, size_t align) {
    /* TODO: double check if this is ok for netstat */
	return kzalloc(size, GFP_KERNEL);
}

/**
 * I/O read/write
 */

u8 readb(const volatile void *addr) {
    return *(const volatile u8 *)addr;
}

u16 readw(const volatile void *addr) {
    return *(const volatile u16 *)addr;
}

u32 readl(const volatile void *addr) {
    return *(const volatile u32 *)addr;
}

void writeb(u8 b, volatile void *addr) {
    *(volatile u8 *)addr = b;
}

void writew(u16 b, volatile void *addr) {
    *(volatile u16 *)addr = b;
}

void writel(u32 b, volatile void *addr) {
    *(volatile u32 *)addr = b;
}

static void bad_io_access(unsigned long port, const char *access)
{
    static int count = 10;
    if (count) {
        count--;
        printk("Bad IO access at port %#lx (%s)\n", port, access);
    }
}

#define IO_COND(addr, is_pio, is_mmio) do {                 \
    unsigned long port = (unsigned long)addr;               \
    if (port >= PIO_RESERVED) {                             \
        is_mmio;                                            \
    } else if (port > PIO_OFFSET) {                         \
        port &= PIO_MASK;                                   \
        is_pio;                                             \
    } else                                                  \
        bad_io_access(port, #is_pio );                      \
    } while (0)

unsigned int ioread8(void *addr) {
    IO_COND(addr, return inb(port), return readb(addr));
    return 0xff;
}

unsigned int ioread16(void *addr) {
    IO_COND(addr, return inw(port), return readw(addr));
    return 0xff;
}

unsigned int ioread32(void *addr) {
    IO_COND(addr, return inl(port), return readl(addr));
    return 0xff;
}

void iowrite8(u8 val, void * addr) {
    IO_COND(addr, outb(val, port), writeb(val, addr));
}

void iowrite16(u16 val, void * addr) {
    IO_COND(addr, outw(val, port), writew(val, addr));
}

void iowrite32(u32 val, void * addr) {
    IO_COND(addr, outl(val, port), writel(val, addr));
}

/* unsigned int ioread8(void *addr) { */
/*     IO_COND(addr, unsigned int val = inb(port); printk("%x => %x\n", port, val); return val;, return readb(addr)); */
/*     return 0xff; */
/* } */

/* unsigned int ioread16(void *addr) { */
/*     IO_COND(addr, unsigned int val = inw(port); printk("%x => %x\n", port, val); return val;, return readw(addr)); */
/*     return 0xff; */
/* } */

/* unsigned int ioread32(void *addr) { */
/*     IO_COND(addr, unsigned int val = inl(port); printk("%x => %x\n", port, val); return val;, return readl(addr)); */
/*     return 0xff; */
/* } */

/* void iowrite8(u8 val, void * addr) { */
/*     IO_COND(addr, printk("%x <= %x\n", port, val); outb(val, port), writeb(val, addr)); */
/* } */

/* void iowrite16(u16 val, void * addr) { */
/*     IO_COND(addr, printk("%x <= %x\n", port, val); outw(val, port), writew(val, addr)); */
/* } */

/* void iowrite32(u32 val, void * addr) { */
/*     IO_COND(addr, printk("%x <= %x\n", port, val); outl(val, port), writel(val, addr)); */
/* } */

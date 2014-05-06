#include <osv/debug.h>

#include <linux/printk.h>
#include <linux/device.h>

struct device_driver *drivers[4];
int nr_driver = 0;

int driver_register(struct device_driver *driver) {
    drivers[nr_driver ++] = driver;
    return 0;
}

int device_register_linux(struct device *dev) {
    int i;
    for (i = 0; i < nr_driver; i ++)
        if (dev->bus->match(dev, drivers[i])) {
            dev->driver = drivers[i];
            return dev->bus->probe(dev);
        }
    return -1;
}

const char * dev_name(const struct device * a) {
	return "virtio";
}

int printk(const char * a, ...) {
    va_list args;
    int r;

    va_start(args, a);
    r = vkprintf(a, args);
    va_end(args);

	return r;
}

int no_printk(const char * a, ...) {
    va_list args;
    int r = 0;

    va_start(args, a);
    /* r = vkprintf(a, args); */
    va_end(args);

	return r;
}

#define ___constant_swab16(x) ((__u16)(				\
	(((__u16)(x) & (__u16)0x00ffU) << 8) |			\
	(((__u16)(x) & (__u16)0xff00U) >> 8)))

__u16 __fswab16(__u16 val) {
	return ___constant_swab16(val);
}

void dump_buf(unsigned char *buf, int len) {
    int i;
    for (i = 0; i < len; i ++) {
        printk("%02x ", buf[i]);
        if (i % 32 == 31)
            printk("\n");
        else if (i % 4 == 3)
            printk(" ");
    }
    printk("\n");
}

/**
 * list
 */

void INIT_LIST_HEAD(struct list_head * a) {
	a->next = a;
    a->prev = a;
}

void __list_add(struct list_head *new, struct list_head *prev, struct list_head *next) {
    prev->next = new;
    new->prev = prev;
    new->next = next;
    next->prev = new;
}

void list_add(struct list_head *new, struct list_head *head) {
    __list_add(new, head, head->next);
}

void list_add_tail(struct list_head * new, struct list_head * head) {
    __list_add(new, head->prev, head);
}

void list_del(struct list_head *entry) {
    entry->prev->next = entry->next;
    entry->next->prev = entry->prev;
    entry->prev = entry->next = 0;
}

int list_empty(const struct list_head *head) {
	return (head->next == head);
}

/**
 * bitops
 */

#define ADDR(x) "+m" (*(volatile long *) (x))
void set_bit(unsigned int a, volatile unsigned long * b) {
	asm volatile("bts %1,%0" : ADDR(b) : "Ir" (a) : "memory");
}

void clear_bit(int a, volatile unsigned long * b) {
	asm volatile("btr %1,%0" : ADDR(b) : "Ir" (a));
}

int constant_test_bit(unsigned int a, const volatile unsigned long * b)
{
    return ((1UL << (a & 31)) & (((const volatile unsigned int *) b)[a >> 5])) != 0;
}

int variable_test_bit(int a, const volatile unsigned long * b)
{
    return ((1UL << (a & 31)) & (((const volatile unsigned int *) b)[a >> 5])) != 0;
}

/**
 * errno
 */

long IS_ERR(const void * a) {
	return ((unsigned long)a >= (unsigned long)-4095);
}

void * ERR_PTR(long a) {
	return (void *)a;
}

long PTR_ERR(const void * a) {
	return (long)a;
}

/**
 * ida
 */

int ida_simple_get(struct ida * a, unsigned int b, unsigned int c, gfp_t d) {
    /* This interface is used to get a unique id as a block index only.
     * It should be safe to simply fetch the next available id.
     */
    static int used = 0;
	return b + (used++);
}

void ida_simple_remove(struct ida * a, unsigned int b) {
}

/**
 * scatterlist
 */
void sg_init_one(struct scatterlist *sg, const void *buf, unsigned int len) {
    sg_init_table(sg, 1);
    sg_set_buf(sg, buf, len);
}

void sg_init_table(struct scatterlist *sg, unsigned int nr_entries) {
    memset(sg, 0, sizeof(*sg) * nr_entries);
}

void sg_set_buf(struct scatterlist *sg, const void *buf, unsigned int len) {
    sg->buf = (void *)buf;
    sg->length = len;
}

struct scatterlist * sg_next(struct scatterlist *sg) {
    sg ++;
	return sg;
}

dma_addr_t sg_phys(struct scatterlist *sg) {
	return virt_to_phys(sg->buf);
}

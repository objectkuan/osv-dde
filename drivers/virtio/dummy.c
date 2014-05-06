#include <asm-generic/iomap.h>
#include <asm-generic/percpu.h>
#include <asm/bitops.h>
#include <asm/current.h>
#include <asm/io.h>
#include <asm/processor.h>
#include <asm/string_64.h>
#include <linux/bio.h>
#include <linux/blkdev.h>
#include <linux/completion.h>
#include <linux/cpumask.h>
#include <linux/delay.h>
#include <linux/device.h>
#include <linux/err.h>
#include <linux/etherdevice.h>
#include <linux/ethtool.h>
#include <linux/freezer.h>
#include <linux/fs.h>
#include <linux/genhd.h>
#include <linux/gfp.h>
#include <linux/hardirq.h>
#include <linux/idr.h>
#include <linux/interrupt.h>
#include <linux/io.h>
#include <linux/ioport.h>
#include <linux/kernel.h>
#include <linux/kobject.h>
#include <linux/kthread.h>
#include <linux/list.h>
#include <linux/mempool.h>
#include <linux/mm.h>
#include <linux/module.h>
#include <linux/net.h>
#include <linux/netdevice.h>
#include <linux/pci.h>
#include <linux/percpu.h>
#include <linux/platform_device.h>
#include <linux/printk.h>
#include <linux/scatterlist.h>
#include <linux/sched.h>
#include <linux/skbuff.h>
#include <linux/slab.h>
#include <linux/slub_def.h>
#include <linux/spinlock.h>
#include <linux/spinlock_api_smp.h>
#include <linux/string_helpers.h>
#include <linux/swab.h>
#include <linux/timer.h>
#include <linux/u64_stats_sync.h>
#include <linux/virtio.h>
#include <linux/virtio_config.h>
#include <linux/vmstat.h>
#include <linux/wait.h>
#include <linux/workqueue.h>

#include <osv/debug.h>
#include "dde.h"

#define DDE_WEAK __attribute__((weak))

#define dde_dummy_printf(...)
#define dde_printf(...) kprintf("[DDE] " __VA_ARGS__)
#define dde_skip(...)

DDE_WEAK void add_disk(struct gendisk * a) {
	dde_printf("add_disk not implemented\n");
}

DDE_WEAK int add_uevent_var(struct kobj_uevent_env * a, const char * b, ...) {
	dde_printf("add_uevent_var not implemented\n");
	return 0;
}

DDE_WEAK struct gendisk * alloc_disk(int a) {
	dde_printf("alloc_disk not implemented\n");
	return 0;
}

DDE_WEAK struct net_device * alloc_etherdev_mqs(int a, unsigned int b, unsigned int c) {
	dde_printf("alloc_etherdev_mqs not implemented\n");
	return 0;
}

DDE_WEAK struct page * alloc_pages(gfp_t a, unsigned int b) {
	dde_printf("alloc_pages not implemented\n");
	return 0;
}

DDE_WEAK void * alloc_pages_exact(size_t a, gfp_t b) {
	dde_printf("alloc_pages_exact not implemented\n");
	return 0;
}

DDE_WEAK void * __alloc_percpu(size_t a, size_t b) {
	dde_printf("__alloc_percpu not implemented\n");
	return 0;
}

DDE_WEAK struct workqueue_struct * __alloc_workqueue_key(const char * a, unsigned int b, int c, struct lock_class_key * d, const char * e) {
	dde_printf("__alloc_workqueue_key not implemented\n");
	return 0;
}

DDE_WEAK void all_vm_events(unsigned long * a) {
	dde_printf("all_vm_events not implemented\n");
}

DDE_WEAK int autoremove_wake_function(wait_queue_t * a, unsigned int b, int c, void * d) {
	dde_printf("autoremove_wake_function not implemented\n");
	return 0;
}

DDE_WEAK struct bio * bio_map_kern(struct request_queue * a, void * b, unsigned int c, gfp_t d) {
	dde_printf("bio_map_kern not implemented\n");
	return 0;
}

DDE_WEAK void bio_put(struct bio * a) {
	dde_printf("bio_put not implemented\n");
}

DDE_WEAK void blk_cleanup_queue(struct request_queue * a) {
	dde_printf("blk_cleanup_queue not implemented\n");
}

DDE_WEAK void __blk_end_request_all(struct request * a, int b) {
	dde_printf("__blk_end_request_all not implemented\n");
}

DDE_WEAK int blk_execute_rq(struct request_queue * a, struct gendisk * b, struct request * c, int d) {
	dde_printf("blk_execute_rq not implemented\n");
	return 0;
}

DDE_WEAK struct request_queue * blk_init_queue(request_fn_proc * a, spinlock_t * b) {
	dde_printf("blk_init_queue not implemented\n");
	return 0;
}

DDE_WEAK struct request * blk_make_request(struct request_queue * a, struct bio * b, gfp_t c) {
	dde_printf("blk_make_request not implemented\n");
	return 0;
}

DDE_WEAK struct request * blk_peek_request(struct request_queue * a) {
	dde_printf("blk_peek_request not implemented\n");
	return 0;
}

DDE_WEAK void blk_put_request(struct request * a) {
	dde_printf("blk_put_request not implemented\n");
}

DDE_WEAK void blk_queue_alignment_offset(struct request_queue * a, unsigned int b) {
	dde_printf("blk_queue_alignment_offset not implemented\n");
}

DDE_WEAK void blk_queue_bounce_limit(struct request_queue * a, u64 b) {
	dde_skip("blk_queue_bounce_limit not implemented\n");
}

DDE_WEAK void blk_queue_flush(struct request_queue * a, unsigned int b) {
	dde_skip("blk_queue_flush not implemented\n");
}

DDE_WEAK void blk_queue_io_min(struct request_queue * a, unsigned int b) {
	dde_printf("blk_queue_io_min not implemented\n");
}

DDE_WEAK void blk_queue_io_opt(struct request_queue * a, unsigned int b) {
	dde_printf("blk_queue_io_opt not implemented\n");
}

DDE_WEAK void blk_queue_logical_block_size(struct request_queue * a, unsigned short b) {
	dde_skip("blk_queue_logical_block_size not implemented\n");
}

DDE_WEAK void blk_queue_max_hw_sectors(struct request_queue * a, unsigned int b) {
	dde_skip("blk_queue_max_hw_sectors not implemented\n");
}

DDE_WEAK void blk_queue_max_segments(struct request_queue * a, unsigned short b) {
	dde_skip("blk_queue_max_segments not implemented\n");
}

DDE_WEAK void blk_queue_max_segment_size(struct request_queue * a, unsigned int b) {
	dde_skip("blk_queue_max_segment_size not implemented\n");
}

DDE_WEAK void blk_queue_physical_block_size(struct request_queue * a, unsigned int b) {
	dde_skip("blk_queue_physical_block_size not implemented\n");
}

DDE_WEAK int blk_rq_map_sg(struct request_queue * a, struct request * b, struct scatterlist * c) {
	dde_printf("blk_rq_map_sg not implemented\n");
	return 0;
}

DDE_WEAK sector_t blk_rq_pos(const struct request * a) {
	dde_printf("blk_rq_pos not implemented\n");
	return 0;
}

DDE_WEAK void blk_start_queue(struct request_queue * a) {
	dde_printf("blk_start_queue not implemented\n");
}

DDE_WEAK void blk_start_request(struct request * a) {
	dde_printf("blk_start_request not implemented\n");
}

DDE_WEAK void blk_stop_queue(struct request_queue * a) {
	dde_printf("blk_stop_queue not implemented\n");
}

DDE_WEAK int bus_register(struct bus_type * a) {
	dde_printf("bus_register not implemented\n");
	return 0;
}

DDE_WEAK void bus_unregister(struct bus_type * a) {
	dde_printf("bus_unregister not implemented\n");
}

DDE_WEAK bool cancel_delayed_work_sync(struct delayed_work * a) {
	dde_printf("cancel_delayed_work_sync not implemented\n");
	return 0;
}

DDE_WEAK void clear_bit(int a, volatile unsigned long * b) {
	dde_printf("clear_bit not implemented\n");
}

DDE_WEAK void complete(struct completion * a) {
	dde_printf("complete not implemented\n");
}

DDE_WEAK int constant_test_bit(unsigned int a, const volatile unsigned long * b)
{
	dde_printf("constant_test_bit not implemented\n");
    return 0;
}

DDE_WEAK void consume_skb(struct sk_buff * a) {
	dde_printf("consume_skb not implemented\n");
}

DDE_WEAK unsigned int cpumask_next(int a, const struct cpumask * b) {
	dde_printf("cpumask_next not implemented\n");
	return 0;
}

const struct cpumask *const cpu_possible_mask;

DDE_WEAK void cpu_relax() {
	dde_printf("cpu_relax not implemented\n");
}

DDE_WEAK void del_gendisk(struct gendisk * a) {
	dde_printf("del_gendisk not implemented\n");
}

DDE_WEAK void destroy_workqueue(struct workqueue_struct * a) {
	dde_printf("destroy_workqueue not implemented\n");
}

DDE_WEAK int dev_err(const struct device * a, const char * b, ...) {
	dde_printf("dev_err not implemented\n");
	return 0;
}

DDE_WEAK int device_create_file(struct device * a, const struct device_attribute * b) {
	dde_skip("device_create_file not implemented\n");
	return 0;
}

DDE_WEAK int device_register_linux(struct device * a) {
	dde_printf("device_register not implemented\n");
	return 0;
}

DDE_WEAK void device_unregister(struct device * a) {
	dde_printf("device_unregister not implemented\n");
}

DDE_WEAK void dev_kfree_skb_any(struct sk_buff * a) {
	dde_printf("dev_kfree_skb_any not implemented\n");
}

DDE_WEAK void * devm_ioremap(struct device * a, resource_size_t b, unsigned long c) {
	dde_printf("devm_ioremap not implemented\n");
	return 0;
}

DDE_WEAK void * devm_kzalloc(struct device * a, size_t b, gfp_t c) {
	dde_printf("devm_kzalloc not implemented\n");
	return 0;
}

DDE_WEAK struct resource * __devm_request_region(struct device * a, struct resource * b, resource_size_t c, resource_size_t d, const char * e) {
	dde_printf("__devm_request_region not implemented\n");
	return 0;
}

DDE_WEAK const char * dev_name(const struct device * a) {
	dde_printf("dev_name not implemented\n");
	return 0;
}

DDE_WEAK int dev_notice(const struct device * a, const char * b, ...) {
	dde_printf("dev_notice not implemented\n");
	return 0;
}

DDE_WEAK int dev_printk(const char * a, const struct device * b, const char * c, ...) {
	dde_printf("dev_printk not implemented\n");
	return 0;
}

DDE_WEAK int dev_set_name(struct device * a, const char * b, ...) {
	dde_skip("dev_set_name not implemented\n");
	return 0;
}

DDE_WEAK int dev_warn(const struct device * a, const char * b, ...) {
	dde_printf("dev_warn not implemented\n");
	return 0;
}

DDE_WEAK int driver_register(struct device_driver * a) {
	dde_printf("driver_register not implemented\n");
	return 0;
}

DDE_WEAK void driver_unregister(struct device_driver * a) {
	dde_printf("driver_unregister not implemented\n");
}

DDE_WEAK void * ERR_PTR(long a) {
	dde_printf("ERR_PTR not implemented\n");
	return 0;
}

DDE_WEAK int eth_mac_addr(struct net_device * a, void * b) {
	dde_printf("eth_mac_addr not implemented\n");
	return 0;
}

DDE_WEAK u32 ethtool_op_get_link(struct net_device * a) {
	dde_printf("ethtool_op_get_link not implemented\n");
	return 0;
}

DDE_WEAK __be16 eth_type_trans(struct sk_buff * a, struct net_device * b) {
	dde_printf("eth_type_trans not implemented\n");
	return 0;
}

DDE_WEAK int eth_validate_addr(struct net_device * a) {
	dde_printf("eth_validate_addr not implemented\n");
	return 0;
}

DDE_WEAK void finish_wait(wait_queue_head_t * a, wait_queue_t * b) {
	dde_printf("finish_wait not implemented\n");
}

DDE_WEAK bool flush_work(struct work_struct * a) {
	dde_printf("flush_work not implemented\n");
	return 0;
}

DDE_WEAK void free_irq(unsigned int a, void * b) {
	dde_printf("free_irq not implemented\n");
}

DDE_WEAK void free_netdev(struct net_device * a) {
	dde_printf("free_netdev not implemented\n");
}

DDE_WEAK void __free_pages(struct page * a, unsigned int b) {
	dde_printf("__free_pages not implemented\n");
}

DDE_WEAK void free_pages_exact(void * a, size_t b) {
	dde_printf("free_pages_exact not implemented\n");
}

DDE_WEAK void free_percpu(void * a) {
	dde_printf("free_percpu not implemented\n");
}

DDE_WEAK int freezing(struct task_struct * a) {
	dde_printf("freezing not implemented\n");
	return 0;
}

DDE_WEAK __u16 __fswab16(__u16 a) {
	dde_printf("__fswab16 not implemented\n");
	return 0;
}

DDE_WEAK sector_t get_capacity(struct gendisk * a) {
	dde_printf("get_capacity not implemented\n");
	return 0;
}

DDE_WEAK struct task_struct * get_current() {
	dde_printf("get_current not implemented\n");
	return 0;
}

DDE_WEAK int ida_simple_get(struct ida * a, unsigned int b, unsigned int c, gfp_t d) {
	dde_printf("ida_simple_get not implemented\n");
	return 0;
}

DDE_WEAK void ida_simple_remove(struct ida * a, unsigned int b) {
	dde_printf("ida_simple_remove not implemented\n");
}

DDE_WEAK void init_completion(struct completion * a) {
	dde_printf("init_completion not implemented\n");
}

DDE_WEAK void INIT_LIST_HEAD(struct list_head * a) {
	dde_printf("INIT_LIST_HEAD not implemented\n");
}

DDE_WEAK void init_timer_key(struct timer_list * a, const char * b, struct lock_class_key * c) {
	dde_printf("init_timer_key not implemented\n");
}

DDE_WEAK void __init_waitqueue_head(wait_queue_head_t * a, struct lock_class_key * b) {
	dde_printf("__init_waitqueue_head not implemented\n");
}

DDE_WEAK void __init_work(struct work_struct * a, int b) {
	dde_printf("__init_work not implemented\n");
}

struct resource iomem_resource;

DDE_WEAK unsigned int ioread16(void * a) {
	dde_printf("ioread16 not implemented\n");
	return 0;
}

DDE_WEAK unsigned int ioread32(void * a) {
	dde_printf("ioread32 not implemented\n");
	return 0;
}

DDE_WEAK unsigned int ioread8(void * a) {
	dde_printf("ioread8 not implemented\n");
	return 0;
}

DDE_WEAK void iowrite16(u16 a, void * b) {
	dde_printf("iowrite16 not implemented\n");
}

DDE_WEAK void iowrite32(u32 a, void * b) {
	dde_printf("iowrite32 not implemented\n");
}

DDE_WEAK void iowrite8(u8 a, void * b) {
	dde_printf("iowrite8 not implemented\n");
}

DDE_WEAK long IS_ERR(const void * a) {
	dde_printf("IS_ERR not implemented\n");
	return 0;
}

DDE_WEAK void kfree(const void * a) {
	dde_printf("kfree not implemented\n");
}

DDE_WEAK void kfree_skb(struct sk_buff * a) {
	dde_printf("kfree_skb not implemented\n");
}

DDE_WEAK void * kmalloc(size_t a, gfp_t b) {
	dde_printf("kmalloc not implemented\n");
	return 0;
}

DDE_WEAK struct task_struct * kthread_create_on_node(int (*a)(void *), void * b, int c, const char d[], ...) {
	dde_printf("kthread_create_on_node not implemented\n");
	return 0;
}

DDE_WEAK int kthread_should_stop() {
	dde_printf("kthread_should_stop not implemented\n");
	return 0;
}

DDE_WEAK int kthread_stop(struct task_struct * a) {
	dde_printf("kthread_stop not implemented\n");
	return 0;
}

DDE_WEAK void * kzalloc(size_t a, gfp_t b) {
	dde_printf("kzalloc not implemented\n");
	return 0;
}

DDE_WEAK void list_add(struct list_head * a, struct list_head * b) {
	dde_printf("list_add not implemented\n");
}

DDE_WEAK void list_add_tail(struct list_head * a, struct list_head * b) {
	dde_printf("list_add_tail not implemented\n");
}

DDE_WEAK void list_del(struct list_head * a) {
	dde_printf("list_del not implemented\n");
}

DDE_WEAK int list_empty(const struct list_head * a) {
	dde_printf("list_empty not implemented\n");
	return 0;
}

DDE_WEAK void * lowmem_page_address(const struct page * a) {
	dde_printf("lowmem_page_address not implemented\n");
	return 0;
}

DDE_WEAK void * memcpy(void * a, const void * b, size_t c) {
	dde_printf("memcpy not implemented\n");
	return 0;
}

DDE_WEAK void * mempool_alloc(mempool_t * a, gfp_t b) {
	dde_printf("mempool_alloc not implemented\n");
	return 0;
}

DDE_WEAK mempool_t * mempool_create_kmalloc_pool(int a, size_t b) {
	dde_printf("mempool_create_kmalloc_pool not implemented\n");
	return 0;
}

DDE_WEAK void mempool_destroy(mempool_t * a) {
	dde_printf("mempool_destroy not implemented\n");
}

DDE_WEAK void mempool_free(void * a, mempool_t * b) {
	dde_printf("mempool_free not implemented\n");
}

DDE_WEAK void * memset(void * a, int b, size_t c) {
	dde_printf("memset not implemented\n");
	return 0;
}

DDE_WEAK ssize_t __modver_version_show(struct module_attribute * a, struct module_kobject * b, char * c) {
	dde_printf("__modver_version_show not implemented\n");
	return 0;
}

DDE_WEAK void msleep(unsigned int a) {
	dde_printf("msleep not implemented\n");
}

DDE_WEAK void napi_complete(struct napi_struct * a) {
	dde_printf("napi_complete not implemented\n");
}

DDE_WEAK void napi_disable(struct napi_struct * a) {
	dde_printf("napi_disable not implemented\n");
}

DDE_WEAK void napi_enable(struct napi_struct * a) {
	dde_printf("napi_enable not implemented\n");
}

DDE_WEAK void __napi_schedule(struct napi_struct * a) {
	dde_printf("__napi_schedule not implemented\n");
}

DDE_WEAK void napi_schedule(struct napi_struct * a) {
	dde_printf("napi_schedule not implemented\n");
}

DDE_WEAK int napi_schedule_prep(struct napi_struct * a) {
	dde_printf("napi_schedule_prep not implemented\n");
	return 0;
}

DDE_WEAK struct sk_buff * netdev_alloc_skb_ip_align(struct net_device * a, unsigned int b) {
	dde_printf("netdev_alloc_skb_ip_align not implemented\n");
	return 0;
}

DDE_WEAK void * netdev_priv(const struct net_device * a) {
	dde_printf("netdev_priv not implemented\n");
	return 0;
}

DDE_WEAK void netif_carrier_off(struct net_device * a) {
	dde_printf("netif_carrier_off not implemented\n");
}

DDE_WEAK void netif_carrier_on(struct net_device * a) {
	dde_printf("netif_carrier_on not implemented\n");
}

DDE_WEAK void netif_napi_add(struct net_device * a, struct napi_struct * b, int (*c)(struct napi_struct *, int), int d) {
	dde_printf("netif_napi_add not implemented\n");
}

DDE_WEAK int netif_receive_skb(struct sk_buff * a) {
	dde_printf("netif_receive_skb not implemented\n");
	return 0;
}

DDE_WEAK void netif_start_queue(struct net_device * a) {
	dde_printf("netif_start_queue not implemented\n");
}

DDE_WEAK void netif_stop_queue(struct net_device * a) {
	dde_printf("netif_stop_queue not implemented\n");
}

DDE_WEAK void netif_wake_queue(struct net_device * a) {
	dde_printf("netif_wake_queue not implemented\n");
}

DDE_WEAK int net_ratelimit() {
	dde_printf("net_ratelimit not implemented\n");
	return 0;
}

DDE_WEAK void nf_reset(struct sk_buff * a) {
	dde_skip("nf_reset not implemented\n");
}

DDE_WEAK int no_printk(const char * a, ...) {
	dde_printf("no_printk not implemented\n");
	return 0;
}

int nr_cpu_ids;

DDE_WEAK void panic(const char * a, ...) {
	dde_printf("panic not implemented\n");
}

DDE_WEAK void pci_disable_device(struct pci_dev * a) {
	dde_printf("pci_disable_device not implemented\n");
}

DDE_WEAK void pci_disable_msix(struct pci_dev * a) {
	dde_printf("pci_disable_msix not implemented\n");
}

DDE_WEAK int pci_enable_device(struct pci_dev * a) {
	dde_printf("pci_enable_device not implemented\n");
	return 0;
}

DDE_WEAK int pci_enable_msix(struct pci_dev * a, struct msix_entry * b, int c) {
	dde_printf("pci_enable_msix not implemented\n");
	return 0;
}

DDE_WEAK void * pci_get_drvdata(struct pci_dev * a) {
	dde_printf("pci_get_drvdata not implemented\n");
	return 0;
}

DDE_WEAK void * pci_iomap(struct pci_dev * a, int b, unsigned long c) {
	dde_printf("pci_iomap not implemented\n");
	return 0;
}

DDE_WEAK void pci_iounmap(struct pci_dev * a, void * b) {
	dde_printf("pci_iounmap not implemented\n");
}

DDE_WEAK void pci_msi_off(struct pci_dev * a) {
	dde_skip("pci_msi_off not implemented\n");
}

DDE_WEAK int __pci_register_driver(struct pci_driver * a, struct module * b, const char * c) {
	dde_printf("__pci_register_driver not implemented\n");
	return 0;
}

DDE_WEAK void pci_release_regions(struct pci_dev * a) {
	dde_printf("pci_release_regions not implemented\n");
}

DDE_WEAK int pci_request_regions(struct pci_dev * a, const char * b) {
	dde_printf("pci_request_regions not implemented\n");
	return 0;
}

DDE_WEAK void pci_restore_state(struct pci_dev * a) {
	dde_printf("pci_restore_state not implemented\n");
}

DDE_WEAK int pci_save_state(struct pci_dev * a) {
	dde_printf("pci_save_state not implemented\n");
	return 0;
}

DDE_WEAK void pci_set_drvdata(struct pci_dev * a, void * b) {
	dde_printf("pci_set_drvdata not implemented\n");
}

DDE_WEAK void pci_set_master(struct pci_dev * a) {
	dde_printf("pci_set_master not implemented\n");
}

DDE_WEAK int pci_set_power_state(struct pci_dev * a, pci_power_t b) {
	dde_printf("pci_set_power_state not implemented\n");
	return 0;
}

DDE_WEAK void pci_unregister_driver(struct pci_driver * a) {
	dde_printf("pci_unregister_driver not implemented\n");
}

unsigned long __per_cpu_offset[64];

DDE_WEAK void * phys_to_virt(phys_addr_t a) {
	dde_printf("phys_to_virt not implemented\n");
	return 0;
}

DDE_WEAK int platform_driver_register(struct platform_driver * a) {
	dde_printf("platform_driver_register not implemented\n");
	return 0;
}

DDE_WEAK void platform_driver_unregister(struct platform_driver * a) {
	dde_printf("platform_driver_unregister not implemented\n");
}

DDE_WEAK void * platform_get_drvdata(const struct platform_device * a) {
	dde_printf("platform_get_drvdata not implemented\n");
	return 0;
}

DDE_WEAK int platform_get_irq(struct platform_device * a, unsigned int b) {
	dde_printf("platform_get_irq not implemented\n");
	return 0;
}

DDE_WEAK struct resource * platform_get_resource(struct platform_device * a, unsigned int b, unsigned int c) {
	dde_printf("platform_get_resource not implemented\n");
	return 0;
}

DDE_WEAK void platform_set_drvdata(struct platform_device * a, void * b) {
	dde_printf("platform_set_drvdata not implemented\n");
}

DDE_WEAK void prepare_to_wait(wait_queue_head_t * a, wait_queue_t * b, int c) {
	dde_printf("prepare_to_wait not implemented\n");
}

DDE_WEAK int printk(const char * a, ...) {
	dde_printf("printk not implemented\n");
	return 0;
}

DDE_WEAK int __printk_ratelimit(const char * a) {
	dde_printf("__printk_ratelimit not implemented\n");
	return 0;
}

DDE_WEAK long PTR_ERR(const void * a) {
	dde_printf("PTR_ERR not implemented\n");
	return 0;
}

DDE_WEAK void put_disk(struct gendisk * a) {
	dde_printf("put_disk not implemented\n");
}

DDE_WEAK unsigned short queue_logical_block_size(struct request_queue * a) {
	dde_printf("queue_logical_block_size not implemented\n");
	return 0;
}

DDE_WEAK int queue_work(struct workqueue_struct * a, struct work_struct * b) {
	dde_printf("queue_work not implemented\n");
	return 0;
}

DDE_WEAK void random_ether_addr(u8 * a) {
	dde_printf("random_ether_addr not implemented\n");
}

DDE_WEAK unsigned long _raw_spin_lock_irqsave(raw_spinlock_t * a) {
	dde_printf("_raw_spin_lock_irqsave not implemented\n");
	return 0;
}

DDE_WEAK unsigned char readb(const volatile void * a) {
	dde_printf("readb not implemented\n");
	return 0;
}

DDE_WEAK unsigned int readl(const volatile void * a) {
	dde_printf("readl not implemented\n");
	return 0;
}

DDE_WEAK int register_blkdev(unsigned int a, const char * b) {
	dde_skip("register_blkdev not implemented\n");
	return 0;
}

DDE_WEAK int register_netdev(struct net_device * a) {
	dde_printf("register_netdev not implemented\n");
	return 0;
}

DDE_WEAK unsigned short req_get_ioprio(struct request * a) {
	dde_printf("req_get_ioprio not implemented\n");
	return 0;
}

DDE_WEAK int request_irq(unsigned int a, irq_handler_t b, unsigned long c, const char * d, void * e) {
	dde_printf("request_irq not implemented\n");
	return 0;
}

DDE_WEAK resource_size_t resource_size(const struct resource * a) {
	dde_printf("resource_size not implemented\n");
	return 0;
}

DDE_WEAK void schedule() {
	dde_printf("schedule not implemented\n");
}

DDE_WEAK int schedule_delayed_work(struct delayed_work * a, unsigned long b) {
	dde_printf("schedule_delayed_work not implemented\n");
	return 0;
}

DDE_WEAK int scsi_cmd_blk_ioctl(struct block_device * a, fmode_t b, unsigned int c, void * d) {
	dde_printf("scsi_cmd_blk_ioctl not implemented\n");
	return 0;
}

DDE_WEAK void set_bit(unsigned int a, volatile unsigned long * b) {
	dde_printf("set_bit not implemented\n");
}

DDE_WEAK void set_capacity(struct gendisk * a, sector_t b) {
	dde_printf("set_capacity not implemented\n");
}

DDE_WEAK void set_disk_ro(struct gendisk * a, int b) {
	dde_printf("set_disk_ro not implemented\n");
}

DDE_WEAK void set_freezable() {
	dde_printf("set_freezable not implemented\n");
}

DDE_WEAK void sg_init_one(struct scatterlist * a, const void * b, unsigned int c) {
	dde_printf("sg_init_one not implemented\n");
}

DDE_WEAK void sg_init_table(struct scatterlist * a, unsigned int b) {
	dde_printf("sg_init_table not implemented\n");
}

DDE_WEAK struct scatterlist * sg_next(struct scatterlist * a) {
	dde_printf("sg_next not implemented\n");
	return 0;
}

DDE_WEAK dma_addr_t sg_phys(struct scatterlist * a) {
	dde_printf("sg_phys not implemented\n");
	return 0;
}

DDE_WEAK void sg_set_buf(struct scatterlist * a, const void * b, unsigned int c) {
	dde_printf("sg_set_buf not implemented\n");
}

DDE_WEAK void * sg_virt(struct scatterlist * a) {
	dde_printf("sg_virt not implemented\n");
	return 0;
}

DDE_WEAK int signal_pending(struct task_struct * a) {
	dde_printf("signal_pending not implemented\n");
	return 0;
}

DDE_WEAK void si_meminfo(struct sysinfo * a) {
	dde_printf("si_meminfo not implemented\n");
}

DDE_WEAK int skb_checksum_start_offset(const struct sk_buff * a) {
	dde_printf("skb_checksum_start_offset not implemented\n");
	return 0;
}

DDE_WEAK unsigned char * skb_end_pointer(const struct sk_buff * a) {
	dde_printf("skb_end_pointer not implemented\n");
	return 0;
}

DDE_WEAK void __skb_fill_page_desc(struct sk_buff * a, int b, struct page * c, int d, int e) {
	dde_printf("__skb_fill_page_desc not implemented\n");
}

DDE_WEAK unsigned int skb_headlen(const struct sk_buff * a) {
	dde_printf("skb_headlen not implemented\n");
	return 0;
}

DDE_WEAK int skb_is_gso(const struct sk_buff * a) {
	dde_printf("skb_is_gso not implemented\n");
	return 0;
}

DDE_WEAK void skb_orphan(struct sk_buff * a) {
	dde_skip("skb_orphan not implemented\n");
}

DDE_WEAK bool skb_partial_csum_set(struct sk_buff * a, u16 b, u16 c) {
	dde_printf("skb_partial_csum_set not implemented\n");
	return 0;
}

DDE_WEAK unsigned char * skb_put(struct sk_buff * a, unsigned int b) {
	dde_printf("skb_put not implemented\n");
	return 0;
}

DDE_WEAK int skb_tailroom(const struct sk_buff * a) {
	dde_printf("skb_tailroom not implemented\n");
	return 0;
}

DDE_WEAK int skb_to_sgvec(struct sk_buff * a, struct scatterlist * b, int c, int d) {
	dde_printf("skb_to_sgvec not implemented\n");
	return 0;
}

DDE_WEAK void skb_trim(struct sk_buff * a, unsigned int b) {
	dde_printf("skb_trim not implemented\n");
}

DDE_WEAK int snprintf(char * a, size_t b, const char * c, ...) {
	dde_printf("snprintf not implemented\n");
	return 0;
}

DDE_WEAK raw_spinlock_t * spinlock_check(spinlock_t * a) {
	dde_printf("spinlock_check not implemented\n");
	return 0;
}

DDE_WEAK void spin_unlock_irqrestore(spinlock_t * a, unsigned long b) {
	dde_printf("spin_unlock_irqrestore not implemented\n");
}

DDE_WEAK int sprintf(char * a, const char * b, ...) {
	dde_printf("sprintf not implemented\n");
	return 0;
}

DDE_WEAK int string_get_size(u64 a, enum string_size_units b, char * c, int d) {
	dde_printf("string_get_size not implemented\n");
	return 0;
}

DDE_WEAK unsigned long strlen(const char * a) {
	dde_printf("strlen not implemented\n");
	return 0;
}

DDE_WEAK void synchronize_irq(unsigned int a) {
	dde_printf("synchronize_irq not implemented\n");
}

unsigned long totalram_pages;

DDE_WEAK int try_to_freeze() {
	dde_printf("try_to_freeze not implemented\n");
	return 0;
}

DDE_WEAK unsigned int u64_stats_fetch_begin(const struct u64_stats_sync * a) {
	dde_printf("u64_stats_fetch_begin not implemented\n");
	return 0;
}

DDE_WEAK bool u64_stats_fetch_retry(const struct u64_stats_sync * a, unsigned int b) {
	dde_printf("u64_stats_fetch_retry not implemented\n");
	return 0;
}

DDE_WEAK void u64_stats_update_begin(struct u64_stats_sync * a) {
	dde_printf("u64_stats_update_begin not implemented\n");
}

DDE_WEAK void u64_stats_update_end(struct u64_stats_sync * a) {
	dde_printf("u64_stats_update_end not implemented\n");
}

DDE_WEAK void unregister_blkdev(unsigned int a, const char * b) {
	dde_printf("unregister_blkdev not implemented\n");
}

DDE_WEAK void unregister_netdev(struct net_device * a) {
	dde_printf("unregister_netdev not implemented\n");
}

DDE_WEAK int variable_test_bit(int a, const volatile unsigned long * b) {
	dde_printf("variable_test_bit not implemented\n");
	return 0;
}

DDE_WEAK phys_addr_t virt_to_phys(volatile void * a) {
	dde_printf("virt_to_phys not implemented\n");
	return 0;
}

DDE_WEAK void wait_for_completion(struct completion * a) {
	dde_printf("wait_for_completion not implemented\n");
}

DDE_WEAK void __wake_up(wait_queue_head_t * a, unsigned int b, int c, void * d) {
	dde_printf("__wake_up not implemented\n");
}

DDE_WEAK int wake_up_process(struct task_struct * a) {
	dde_printf("wake_up_process not implemented\n");
	return 0;
}

DDE_WEAK void writeb(unsigned char a, volatile void * b) {
	dde_printf("writeb not implemented\n");
}

DDE_WEAK void writel(unsigned int a, volatile void * b) {
	dde_printf("writel not implemented\n");
}

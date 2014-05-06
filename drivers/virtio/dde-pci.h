#ifndef DDE_PCI_H
#define DDE_PCI_H

#ifdef __cplusplus
extern "C" {
#endif

struct msix_entry;

#define PIO_OFFSET    0x10000UL
#define PIO_MASK      0x0ffffUL
#define PIO_RESERVED  0x40000UL

void *dde_map_bar(void *dev, int bar_id);
void dde_set_master(void *dev);
void dde_enable_msix(void *dev, struct msix_entry *entries, int nr_entry);

#ifdef __cplusplus
class interrupt_manager;
class msix_vector;

struct msix_detail {
    interrupt_manager *mgr;
    int entry;
    msix_vector *vec;
};
#endif

#ifdef __cplusplus
}
#endif

#endif /* ! DDE_PCI_H */

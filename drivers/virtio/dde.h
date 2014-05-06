#ifndef DDE_H
#define DDE_H

#ifdef __cplusplus
extern "C" {
#endif

struct pci_dev;

struct pci_dev *dde_alloc_pci_dev(u16 device, u8 revision, u16 subvendor, u16 subdevice, u8 irq, void *priv);
int dde_pci_probe(struct pci_dev *dev);

#ifdef __cplusplus
}
#endif

#endif /* ! DDE_H */

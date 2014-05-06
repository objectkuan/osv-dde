#include "dde.h"
#include "dde-pci.h"

#include <asm-generic/int-ll64.h>
#include <asm-generic/errno-base.h>
#include <linux/pci.h>

#include <osv/debug.h>

static struct pci_driver *virtio_pci_driver = 0;

void pci_set_drvdata(struct pci_dev *dev, void *data) {
	dev->drv_data = data;
}

void *pci_get_drvdata(struct pci_dev *dev) {
	return dev->drv_data;
}

int __pci_register_driver(struct pci_driver *drv, struct module *mod, const char *mod_name) {
	virtio_pci_driver = drv;
	return 0;
}

void *pci_iomap(struct pci_dev *dev, int bar, unsigned long max) {
    return dde_map_bar(dev->priv, bar);
}

void pci_set_master(struct pci_dev *dev) {
    dde_set_master(dev->priv);
}

int pci_enable_msix(struct pci_dev *dev, struct msix_entry *entries, int nr_entry) {
	dde_enable_msix(dev->priv, entries, nr_entry);
    return 0;
}

int pci_request_regions(struct pci_dev * a, const char * b) {
	return 0;
}

int pci_enable_device(struct pci_dev * a) {
    return 0;
}


struct pci_dev *dde_alloc_pci_dev(u16 device, u8 revision, u16 subvendor, u16 subdevice, u8 irq, void *priv)
{
    struct pci_dev *dev = kmalloc(sizeof(struct pci_dev), GFP_KERNEL);;
    if (!dev)
        return 0;

    dev->device = device;
    dev->revision = revision;
    dev->irq = irq;
    dev->subsystem_vendor = subvendor;
    dev->subsystem_device = subdevice;
    dev->priv = priv;
    return dev;
}

int dde_pci_probe(struct pci_dev *dev) {
    if (virtio_pci_driver == 0)
        return -ENODEV;
    return virtio_pci_driver->probe(dev, 0);
}

#ifndef __LINUX_PCI_H__
#define __LINUX_PCI_H__

/*0*/ #include <linux/pci.h>
/*43*/ #include <linux/mod_devicetable.h>
/*45*/ #include <linux/types.h>
/*47*/ #include <linux/ioport.h>
/*48*/ #include <linux/list.h>
/*50*/ #include <linux/errno.h>
/*51*/ #include <linux/kobject.h>
/*53*/ #include <linux/device.h>
/*54*/ #include <linux/io.h>
/*55*/ #include <linux/irqreturn.h>
/*117*/ typedef int pci_power_t;
/*119*/ #define PCI_D0 ((pci_power_t __force) 0)
/*122*/ #define PCI_D3hot ((pci_power_t __force) 3)
/**348**/ struct pci_dev {
	union { struct pci_sriov * sriov; struct pci_dev * physfn; };
	unsigned int irq;
	unsigned short device;
	u8 revision;
	struct device dev;
	unsigned short subsystem_vendor;
	unsigned short subsystem_device;
    void *drv_data;
    void *priv;
};
/**565**/ struct pci_driver {
	const char * name;
	const struct pci_device_id * id_table;
	int (*probe)(struct pci_dev *, const struct pci_device_id *);
	void (*remove)(struct pci_dev *);
	int (*suspend)(struct pci_dev *, pm_message_t);
	int (*resume)(struct pci_dev *);
};
/*576*/ #define DEFINE_PCI_DEVICE_TABLE(_table) const struct pci_device_id _table[] __devinitconst
/*779*/ int pci_enable_device(struct pci_dev * a);
/*796*/ void pci_disable_device(struct pci_dev * a);
/*797*/ void pci_set_master(struct pci_dev * a);
/*806*/ void pci_msi_off(struct pci_dev * a);
/*831*/ int pci_save_state(struct pci_dev * a);
/*832*/ void pci_restore_state(struct pci_dev * a);
/*838*/ int pci_set_power_state(struct pci_dev * a, pci_power_t b);
/*902*/ int pci_request_regions(struct pci_dev * a, const char * b);
/*904*/ void pci_release_regions(struct pci_dev * a);
/*935*/ int __pci_register_driver(struct pci_driver * a, struct module * b, const char * c);
/*940*/ #define pci_register_driver(driver) __pci_register_driver(driver, THIS_MODULE, KBUILD_MODNAME)
/*943*/ void pci_unregister_driver(struct pci_driver * a);
/**992**/ struct msix_entry {
	u32 vector;
	u16 entry;
};
/*1036*/ int pci_enable_msix(struct pci_dev * a, struct msix_entry * b, int c);
/*1038*/ void pci_disable_msix(struct pci_dev * a);
/*1338*/ void * pci_get_drvdata(struct pci_dev * a);
/*1343*/ void pci_set_drvdata(struct pci_dev * a, void * b);
/*1391*/ #define DECLARE_PCI_FIXUP_SECTION(section,name,vendor,device,hook) static const struct pci_fixup __pci_fixup_##name __used __attribute__((__section__(#section))) = { vendor, device, hook };
/*1400*/ #define DECLARE_PCI_FIXUP_FINAL(vendor,device,hook) DECLARE_PCI_FIXUP_SECTION(.pci_fixup_final, vendor##device##hook, vendor, device, hook)

#endif

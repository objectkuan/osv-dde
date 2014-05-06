#ifndef __ASM_GENERIC_IOMAP_H__
#define __ASM_GENERIC_IOMAP_H__

/*0*/ struct pci_dev;
/*0*/ #include <linux/pci.h>
/*28*/ unsigned int ioread8(void * a);
/*29*/ unsigned int ioread16(void * a);
/*31*/ unsigned int ioread32(void * a);
/*34*/ void iowrite8(u8 a, void * b);
/*35*/ void iowrite16(u16 a, void * b);
/*37*/ void iowrite32(u32 a, void * b);
/*72*/ void * pci_iomap(struct pci_dev * a, int b, unsigned long c);
/*73*/ void pci_iounmap(struct pci_dev * a, void * b);

#endif

#ifndef __LINUX_MOD_DEVICETABLE_H__
#define __LINUX_MOD_DEVICETABLE_H__

/*0*/ #include <linux/mod_devicetable.h>
/*11*/ #include <linux/types.h>
/*12*/ typedef unsigned long kernel_ulong_t;
/*15*/ #define PCI_ANY_ID (~0)
/*22*/ struct pci_device_id { __u32 vendor; __u32 device; __u32 subvendor; __u32 subdevice; __u32 clazz; __u32 class_mask; kernel_ulong_t driver_data; };
/**229**/ struct of_device_id {
	char compatible[128];
};
/*405*/ struct virtio_device_id { __u32 device; __u32 vendor; };
/*406*/ #define VIRTIO_DEV_ANY_ID 0xffffffff

#endif

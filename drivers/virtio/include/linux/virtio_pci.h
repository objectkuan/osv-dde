#ifndef __LINUX_VIRTIO_PCI_H__
#define __LINUX_VIRTIO_PCI_H__

/*42*/ #include <linux/virtio_config.h>
/*45*/ #define VIRTIO_PCI_HOST_FEATURES 0
/*48*/ #define VIRTIO_PCI_GUEST_FEATURES 4
/*51*/ #define VIRTIO_PCI_QUEUE_PFN 8
/*54*/ #define VIRTIO_PCI_QUEUE_NUM 12
/*57*/ #define VIRTIO_PCI_QUEUE_SEL 14
/*60*/ #define VIRTIO_PCI_QUEUE_NOTIFY 16
/*63*/ #define VIRTIO_PCI_STATUS 18
/*68*/ #define VIRTIO_PCI_ISR 19
/*71*/ #define VIRTIO_PCI_ISR_CONFIG 0x2
/*75*/ #define VIRTIO_MSI_CONFIG_VECTOR 20
/*77*/ #define VIRTIO_MSI_QUEUE_VECTOR 22
/*79*/ #define VIRTIO_MSI_NO_VECTOR 0xffff
/*83*/ #define VIRTIO_PCI_CONFIG(dev) ((dev)->msix_enabled ? 24 : 20)
/*86*/ #define VIRTIO_PCI_ABI_VERSION 0
/*90*/ #define VIRTIO_PCI_QUEUE_ADDR_SHIFT 12
/*94*/ #define VIRTIO_PCI_VRING_ALIGN 4096

#endif

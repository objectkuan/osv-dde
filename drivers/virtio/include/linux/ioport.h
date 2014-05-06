#ifndef __LINUX_IOPORT_H__
#define __LINUX_IOPORT_H__

/*0*/ struct device;
/*0*/ #include <linux/device.h>
/*13*/ #include <linux/types.h>
/**24**/ struct resource {
	resource_size_t start;
};
/*39*/ #define IORESOURCE_MEM 0x00000200
/*144*/ extern struct resource iomem_resource;
/*172*/ resource_size_t resource_size(const struct resource * a);
/*211*/ #define devm_request_mem_region(dev,start,n,name) __devm_request_region(dev, &iomem_resource, (start), (n), (name))
/*216*/ struct resource * __devm_request_region(struct device * a, struct resource * b, resource_size_t c, resource_size_t d, const char * e);

#endif

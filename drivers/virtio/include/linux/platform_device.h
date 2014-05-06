#ifndef __LINUX_PLATFORM_DEVICE_H__
#define __LINUX_PLATFORM_DEVICE_H__

/*0*/ struct platform_device;
/*0*/ #include <linux/platform_device.h>
/*14*/ #include <linux/device.h>
/*15*/ #include <linux/mod_devicetable.h>
/**33**/ struct platform_device {
	struct device dev;
	const char * name;
};
/*46*/ struct resource * platform_get_resource(struct platform_device * a, unsigned int b, unsigned int c);
/*47*/ int platform_get_irq(struct platform_device * a, unsigned int b);
/**172**/ struct platform_driver {
	int (*probe)(struct platform_device *);
	int (*remove)(struct platform_device *);
	struct device_driver driver;
};
/*174*/ int platform_driver_register(struct platform_driver * a);
/*175*/ void platform_driver_unregister(struct platform_driver * a);
/*186*/ void * platform_get_drvdata(const struct platform_device * a);
/*191*/ void platform_set_drvdata(struct platform_device * a, void * b);

#endif

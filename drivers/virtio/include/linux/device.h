#ifndef __LINUX_DEVICE_H__
#define __LINUX_DEVICE_H__

/*0*/ struct attribute;
/*0*/ #include <linux/sysfs.h>
/*0*/ struct device;
/*0*/ #include <linux/device.h>
/*0*/ struct device_driver;
/*16*/ #include <linux/ioport.h>
/*17*/ #include <linux/kobject.h>
/*19*/ #include <linux/list.h>
/*20*/ #include <linux/lockdep.h>
/*22*/ #include <linux/types.h>
/*23*/ #include <linux/mutex.h>
/*24*/ #include <linux/pm.h>
/**107**/ struct bus_type {
	const char * name;
	int (*match)(struct device *, struct device_driver *);
	struct device_attribute * dev_attrs;
	int (*uevent)(struct device *, struct kobj_uevent_env *);
	int (*probe)(struct device *);
	int (*remove)(struct device *);
};
/*109*/ int bus_register(struct bus_type * a);
/*110*/ void bus_unregister(struct bus_type * a);
/**213**/ struct device_driver {
	const char * name;
	struct module * owner;
	struct bus_type * bus;
	const struct of_device_id * of_match_table;
};
/*216*/ int driver_register(struct device_driver * a);
/*217*/ void driver_unregister(struct device_driver * a);
/*236*/ #define DRIVER_ATTR(_name,_mode,_show,_store) struct driver_attribute driver_attr_##_name = __ATTR(_name, _mode, _show, _store)
/**439**/ struct device_attribute {
	struct attribute attr;
	ssize_t (*show)(struct device *, struct device_attribute *, char *);
	ssize_t (*store)(struct device *, struct device_attribute *, const char *, size_t);
};
/*441*/ #define DEVICE_ATTR(_name,_mode,_show,_store) struct device_attribute dev_attr_##_name = __ATTR(_name, _mode, _show, _store)
/*445*/ int device_create_file(struct device * a, const struct device_attribute * b);
/*490*/ void * devm_kzalloc(struct device * a, size_t b, gfp_t c);
/**612**/ struct device {
	struct device_driver * driver;
	struct bus_type * bus;
	struct device * parent;
	void (*release)(struct device *);
};
/*624*/ const char * dev_name(const struct device * a);
/*627*/ int dev_set_name(struct device * a, const char * b, ...);
/*710*/ int device_register_linux(struct device * a);
/*711*/ void device_unregister(struct device * a);
/*815*/ int dev_printk(const char * a, const struct device * b, const char * c, ...);
/*824*/ int dev_err(const struct device * a, const char * b, ...);
/*826*/ int dev_warn(const struct device * a, const char * b, ...);
/*828*/ int dev_notice(const struct device * a, const char * b, ...);

#endif

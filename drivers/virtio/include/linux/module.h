#ifndef __LINUX_MODULE_H__
#define __LINUX_MODULE_H__

/*0*/ struct module_attribute;
/*0*/ #include <linux/module.h>
/*0*/ struct module_kobject;
/*9*/ #include <linux/list.h>
/*10*/ #include <linux/stat.h>
/*15*/ #include <linux/stringify.h>
/*16*/ #include <linux/kobject.h>
/*17*/ #include <linux/moduleparam.h>
/*19*/ #include <linux/export.h>
/*21*/ #include <linux/percpu.h>
/**44**/ struct module_kobject {
};
/**55**/ struct module_attribute {
	struct attribute attr;
	ssize_t (*show)(struct module_attribute *, struct module_kobject *, char *);
};
/**61**/ struct module_version_attribute {
	struct module_attribute mattr;
	const char * module_name;
	const char * version;
};
/*64*/ ssize_t __modver_version_show(struct module_attribute * a, struct module_kobject * b, char * c);
/*90*/ #define MODULE_GENERIC_TABLE(gtype,name) 
/*94*/ #define MODULE_INFO(tag,info) __MODULE_INFO(tag, tag, info)
/*127*/ #define MODULE_LICENSE(_license) 
/*133*/ #define MODULE_AUTHOR(_author) 
/*136*/ #define MODULE_DESCRIPTION(_description) 
/*138*/ #define MODULE_DEVICE_TABLE(type,name) MODULE_GENERIC_TABLE(type##_device,name)
/*159*/ #define MODULE_VERSION(_version) static struct module_version_attribute ___modver_attr = { .mattr = { .attr = { .name = "version", .mode = S_IRUGO, }, .show = __modver_version_show, }, .module_name = KBUILD_MODNAME, .version = _version, }; static const struct module_version_attribute __used __attribute__ ((__section__ ("__modver"))) * __moduleparam_const __modver_attr = &___modver_attr
/*639*/ #define __MODULE_STRING(x) __stringify(x)

#endif

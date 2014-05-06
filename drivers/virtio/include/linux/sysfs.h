#ifndef __LINUX_SYSFS_H__
#define __LINUX_SYSFS_H__

/*0*/ #include <linux/types.h>
/*16*/ #include <linux/errno.h>
/*17*/ #include <linux/list.h>
/*18*/ #include <linux/lockdep.h>
/**33**/ struct attribute {
	const char * name;
	mode_t mode;
};
/*70*/ #define __ATTR(_name,_mode,_show,_store) { .attr = {.name = __stringify(_name), .mode = _mode }, .show = _show, .store = _store, }
/*76*/ #define __ATTR_RO(_name) { .attr = { .name = __stringify(_name), .mode = 0444 }, .show = _name##_show, }
/*81*/ #define __ATTR_NULL { .attr = { .name = NULL } }

#endif

#ifndef __LINUX_KOBJECT_H__
#define __LINUX_KOBJECT_H__

/*19*/ #include <linux/types.h>
/*20*/ #include <linux/list.h>
/*21*/ #include <linux/sysfs.h>
/*23*/ #include <linux/spinlock.h>
/*26*/ #include <linux/kernel.h>
/*27*/ #include <linux/wait.h>
/**121**/ struct kobj_uevent_env {
};
/*214*/ int add_uevent_var(struct kobj_uevent_env * a, const char * b, ...);

#endif

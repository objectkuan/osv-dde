#ifndef __LINUX_NOTIFIER_H__
#define __LINUX_NOTIFIER_H__

/*12*/ #include <linux/errno.h>
/*13*/ #include <linux/mutex.h>
/*14*/ #include <linux/rwsem.h>
/*106*/ #define BLOCKING_NOTIFIER_HEAD(name) struct blocking_notifier_head name = BLOCKING_NOTIFIER_INIT(name)

#endif

#ifndef __LINUX_MUTEX_H__
#define __LINUX_MUTEX_H__

/*13*/ #include <linux/list.h>
/*14*/ #include <linux/spinlock_types.h>
/*16*/ #include <linux/lockdep.h>
/*80*/ #define __DEBUG_MUTEX_INITIALIZER(lockname) 
/*102*/ #define __DEP_MAP_MUTEX_INITIALIZER(lockname) 
/*112*/ #define DEFINE_MUTEX(mutexname) struct mutex mutexname = __MUTEX_INITIALIZER(mutexname)

#endif

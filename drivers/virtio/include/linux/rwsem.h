#ifndef __LINUX_RWSEM_H__
#define __LINUX_RWSEM_H__

/*12*/ #include <linux/types.h>
/*13*/ #include <linux/kernel.h>
/*14*/ #include <linux/list.h>
/*15*/ #include <linux/spinlock.h>
/*17*/ #include <asm/system.h>
/*56*/ #define __RWSEM_DEP_MAP_INIT(lockname) 
/*59*/ #define __RWSEM_INITIALIZER(name) { RWSEM_UNLOCKED_VALUE, __RAW_SPIN_LOCK_UNLOCKED(name.wait_lock), LIST_HEAD_INIT((name).wait_list) __RWSEM_DEP_MAP_INIT(name) }
/*65*/ #define DECLARE_RWSEM(name) struct rw_semaphore name = __RWSEM_INITIALIZER(name)

#endif

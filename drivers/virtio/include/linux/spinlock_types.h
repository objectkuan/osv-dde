#ifndef __LINUX_SPINLOCK_TYPES_H__
#define __LINUX_SPINLOCK_TYPES_H__

/*0*/ struct raw_spinlock;
/*0*/ #include <linux/spinlock_types.h>
/*0*/ struct arch_spinlock;
/*13*/ #include <asm/spinlock_types.h>
/*18*/ #include <linux/lockdep.h>
/**32**/ struct raw_spinlock {
	arch_spinlock_t raw_lock;
};
/*32*/ typedef struct raw_spinlock raw_spinlock_t;
/*41*/ #define SPIN_DEP_MAP_INIT(lockname)
/*50*/ #define SPIN_DEBUG_INIT(lockname)
/*53*/ #define __RAW_SPIN_LOCK_INITIALIZER(lockname) { .raw_lock = __ARCH_SPIN_LOCK_UNLOCKED, SPIN_DEBUG_INIT(lockname) SPIN_DEP_MAP_INIT(lockname) }
/*59*/ #define __RAW_SPIN_LOCK_UNLOCKED(lockname) (raw_spinlock_t) __RAW_SPIN_LOCK_INITIALIZER(lockname)
/*76*/ typedef struct spinlock spinlock_t;
/*76*/ struct spinlock { union { struct raw_spinlock rlock; }; };
/*78*/ #define __SPIN_LOCK_INITIALIZER(lockname) { { .rlock = __RAW_SPIN_LOCK_INITIALIZER(lockname) } }
/*81*/ #define __SPIN_LOCK_UNLOCKED(lockname)  __SPIN_LOCK_INITIALIZER(lockname)
/*84*/ #define DEFINE_SPINLOCK(x) spinlock_t x = __SPIN_LOCK_UNLOCKED(x)

#endif

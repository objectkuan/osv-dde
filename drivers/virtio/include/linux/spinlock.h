#ifndef __LINUX_SPINLOCK_H__
#define __LINUX_SPINLOCK_H__

/*49*/ #include <linux/typecheck.h>
/*55*/ #include <linux/kernel.h>
/*56*/ #include <linux/stringify.h>
/*59*/ #include <asm/system.h>
/*81*/ #include <linux/spinlock_types.h>
/*103*/ #define raw_spin_lock_init(lock) do { *(lock) = __RAW_SPIN_LOCK_UNLOCKED(lock); } while (0)
/*188*/ #define raw_spin_lock_irqsave(lock,flags) do { typecheck(unsigned long, flags); flags = _raw_spin_lock_irqsave(lock); } while (0)
/*263*/ #include <linux/spinlock_api_smp.h>
/*275*/ raw_spinlock_t * spinlock_check(spinlock_t * a);
/*277*/ #define spin_lock_init(_lock) do { spinlock_check(_lock); raw_spin_lock_init(&(_lock)->rlock); } while (0)
/*313*/ #define spin_lock_irqsave(lock,flags) do { raw_spin_lock_irqsave(spinlock_check(lock), flags); } while (0)
/*341*/ void spin_unlock_irqrestore(spinlock_t * a, unsigned long b);

#endif

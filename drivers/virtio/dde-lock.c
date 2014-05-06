#include <linux/spinlock.h>

#include "dde-lock.h"

raw_spinlock_t * spinlock_check(spinlock_t *a) {
	return &a->rlock;
}

unsigned long _raw_spin_lock_irqsave(raw_spinlock_t *lock) {
    if (lock->raw_lock.priv == 0)
        lock->raw_lock.priv = dde_new_spin_lock();
	return dde_spin_lock_irqsave(lock->raw_lock.priv);
}

void spin_unlock_irqrestore(spinlock_t *lock, unsigned long enabled) {
    dde_spin_unlock_irqrestore(lock->rlock.raw_lock.priv, enabled);
}

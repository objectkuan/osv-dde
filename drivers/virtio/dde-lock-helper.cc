#include "dde-lock.h"

#include <osv/spinlock.h>
#include <arch.hh>

void *dde_new_spin_lock(void) {
    return new spinlock();
}

int dde_spin_lock_irqsave(void *lock) {
    int ret = arch::irq_enabled();
    spinlock_t *spinlock = (spinlock_t *)lock;
    arch::irq_disable_notrace();
    spinlock->lock();
    return ret;
}

void dde_spin_unlock_irqrestore(void *lock, int enabled) {
    spinlock_t *spinlock = (spinlock_t *)lock;
    spinlock->unlock();
    if (enabled)
        arch::irq_enable();
}

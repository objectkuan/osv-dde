/*
 * Copyright (C) 2013 Cloudius Systems, Ltd.
 *
 * This work is open source software, licensed under the terms of the
 * BSD license as described in the LICENSE file in the top-level directory.
 */

#ifndef __IRQ_PREEMPT_LOCK_H__
#define __IRQ_PREEMPT_LOCK_H__

#ifdef __cplusplus
#include <sched.hh>
#include <osv/spinlock.h>

#define LLLEN 1024

int irq_preempt_lock_irq = 0;
__thread unsigned long long lll[LLLEN];
__thread unsigned long long uuu[LLLEN];
__thread unsigned long long ucounter = 0;
__thread unsigned long long lcounter = 0;
__thread int lp = 0;
__thread int up = 0;
__thread unsigned long long* rbp;


class irq_preempt_lock_t {
private:
spinlock_t spinlock;

int dde_spin_lock_irqsave() {
    int ret = arch::irq_enabled();
    arch::irq_disable_notrace();
    spinlock.lock();
    return ret;
}

void dde_spin_unlock_irqrestore(int enabled) {
    spinlock.unlock();
    if (enabled)
        arch::irq_enable();
}

public:
    void lock() {
	 lll[lp++] = (unsigned long long) __builtin_return_address(0);
	 if(lp >= LLLEN) lcounter++;
	 lp %= LLLEN;
         sched::preempt_disable();
         irq_preempt_lock_irq = dde_spin_lock_irqsave();
    }
    void unlock() {  
	 uuu[up++] = (unsigned long long) __builtin_return_address(0);
	 if(up >= LLLEN) ucounter++;
	 up %= LLLEN;
         dde_spin_unlock_irqrestore(irq_preempt_lock_irq);
         sched::preempt_enable();
    }

    irq_preempt_lock_t()  {}
    ~irq_preempt_lock_t() {}
};

namespace {
    irq_preempt_lock_t irq_preempt_lock;
}

#endif

#endif // !__IRQ_PREEMPT_LOCK_H__


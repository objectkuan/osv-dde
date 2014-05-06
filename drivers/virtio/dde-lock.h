#ifndef DDE_LOCK_H
#define DDE_LOCK_H

#ifdef __cplusplus
extern "C" {
#endif

void *dde_new_spin_lock(void);
int dde_spin_lock_irqsave(void *lock);
void dde_spin_unlock_irqrestore(void *lock, int enabled);

#ifdef __cplusplus
}
#endif

#endif /* ! DDE_LOCK_H */

#ifndef DDE_THREAD_H
#define DDE_THREAD_H

#ifdef __cplusplus
extern "C" {
#endif

#define IRQ_MSIX_FLAG  0x80000000UL

#include <linux/irqreturn.h>
typedef irqreturn_t (*irq_handler_t)(int, void *);

void dde_init_workqueue(void);
void dde_gsi_request_irq(unsigned int irq, irq_handler_t handler, void *dev);
void dde_msix_request_irq(unsigned int irq, irq_handler_t handler, void *dev);

#ifdef __cplusplus
}
#endif

#endif  /* ! DDE_THREAD_H */

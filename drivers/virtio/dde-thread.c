#include "dde.h"
#include "dde-thread.h"

#include <linux/workqueue.h>
#include <linux/interrupt.h>

struct workqueue_struct  {
} dummy_wq;

struct workqueue_struct * __alloc_workqueue_key(const char * a, unsigned int b, int c, struct lock_class_key * d, const char * e) {
    dde_init_workqueue();
	return &dummy_wq;
}

void __init_work(struct work_struct * a, int b) {
    /* The function has been saved in the macro. Nothing more to do here. */
}

int request_irq(unsigned int irq, irq_handler_t handler, unsigned long c, const char * d, void *dev) {
    if (irq & IRQ_MSIX_FLAG)
        dde_msix_request_irq(irq, handler, dev);
    else
        dde_gsi_request_irq(irq, handler, dev);

	return 0;
}

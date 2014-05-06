#ifndef __LINUX_INTERRUPT_H__
#define __LINUX_INTERRUPT_H__

/*0*/ #include <linux/interrupt.h>
/*5*/ #include <linux/kernel.h>
/*7*/ #include <linux/bitops.h>
/*9*/ #include <linux/cpumask.h>
/*10*/ #include <linux/irqreturn.h>
/*12*/ #include <linux/hardirq.h>
/*15*/ #include <linux/percpu.h>
/*18*/ #include <linux/workqueue.h>
/*22*/ #include <asm/system.h>
/*67*/ #define IRQF_SHARED 0x00000080
/*93*/ typedef irqreturn_t (*irq_handler_t)(int, void *);
/*138*/ int request_irq(unsigned int a, irq_handler_t b, unsigned long c, const char * d, void * e);
/*186*/ void free_irq(unsigned int a, void * b);

#endif

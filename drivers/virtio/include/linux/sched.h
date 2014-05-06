#ifndef __LINUX_SCHED_H__
#define __LINUX_SCHED_H__

/*55*/ #include <linux/kernel.h>
/*56*/ #include <linux/types.h>
/*59*/ #include <linux/rbtree.h>
/*61*/ #include <linux/cpumask.h>
/*62*/ #include <linux/errno.h>
/*64*/ #include <linux/mm_types.h>
/*66*/ #include <asm/system.h>
/*75*/ #include <linux/completion.h>
/*77*/ #include <linux/percpu.h>
/*88*/ #include <linux/timer.h>
/*95*/ #include <asm/processor.h>
/*184*/ #define TASK_INTERRUPTIBLE 1
/*185*/ #define TASK_UNINTERRUPTIBLE 2
/*208*/ #define TASK_NORMAL (TASK_INTERRUPTIBLE | TASK_UNINTERRUPTIBLE)
/*249*/ #include <linux/spinlock.h>
/*361*/ void schedule();
/*516*/ #include <linux/rwsem.h>
/**1575**/ struct task_struct {
};
/*2132*/ #include <asm/current.h>
/*2137*/ int wake_up_process(struct task_struct * a);
/*2493*/ int signal_pending(struct task_struct * a);

#endif

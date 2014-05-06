#ifndef __LINUX_WAIT_H__
#define __LINUX_WAIT_H__

/*0*/ #include <linux/wait.h>
/*0*/ struct __wait_queue;
/*22*/ #include <linux/list.h>
/*23*/ #include <linux/stddef.h>
/*24*/ #include <linux/spinlock.h>
/*25*/ #include <asm/system.h>
/*26*/ #include <asm/current.h>
/*28*/ typedef struct __wait_queue wait_queue_t;
/*29*/ typedef int (*wait_queue_func_t)(wait_queue_t *, unsigned int, int, void *);
/**38**/ struct __wait_queue {
	struct list_head task_list;
	void * private;
	wait_queue_func_t func;
};
/**53**/ struct __wait_queue_head {
};
/*54*/ typedef struct __wait_queue_head wait_queue_head_t;
/*74*/ #define DECLARE_WAIT_QUEUE_HEAD(name) wait_queue_head_t name = __WAIT_QUEUE_HEAD_INITIALIZER(name)
/*80*/ void __init_waitqueue_head(wait_queue_head_t * a, struct lock_class_key * b);
/*82*/ #define init_waitqueue_head(q) do { static struct lock_class_key __key; __init_waitqueue_head((q), &__key); } while (0)
/*156*/ void __wake_up(wait_queue_head_t * a, unsigned int b, int c, void * d);
/*170*/ #define wake_up(x) __wake_up(x, TASK_NORMAL, 1, NULL)
/*263*/ #define __wait_event_interruptible(wq,condition,ret) do { DEFINE_WAIT(__wait); for (;;) { prepare_to_wait(&wq, &__wait, TASK_INTERRUPTIBLE); if (condition) break; if (!signal_pending(current)) { schedule(); continue; } ret = -ERESTARTSYS; break; } finish_wait(&wq, &__wait); } while (0)
/*296*/ #define wait_event_interruptible(wq,condition) ({ int __ret = 0; if (!(condition)) __wait_event_interruptible(wq, condition, __ret); __ret; })
/*584*/ void prepare_to_wait(wait_queue_head_t * a, wait_queue_t * b, int c);
/*586*/ void finish_wait(wait_queue_head_t * a, wait_queue_t * b);
/*589*/ int autoremove_wake_function(wait_queue_t * a, unsigned int b, int c, void * d);
/*592*/ #define DEFINE_WAIT_FUNC(name,function) wait_queue_t name = { .private = current, .func = function, .task_list = LIST_HEAD_INIT((name).task_list), }
/*599*/ #define DEFINE_WAIT(name) DEFINE_WAIT_FUNC(name, autoremove_wake_function)

#endif

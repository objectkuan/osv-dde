#ifndef __LINUX_KTHREAD_H__
#define __LINUX_KTHREAD_H__

/*0*/ struct task_struct;
/*4*/ #include <linux/err.h>
/*5*/ #include <linux/sched.h>
/*11*/ struct task_struct * kthread_create_on_node(int (*a)(void *), void * b, int c, const char d[], ...);
/*13*/ #define kthread_create(threadfn,data,namefmt,arg...) kthread_create_on_node(threadfn, data, -1, namefmt, ##arg)
/*26*/ #define kthread_run(threadfn,data,namefmt,...) ({ struct task_struct *__k = kthread_create(threadfn, data, namefmt, ## __VA_ARGS__); if (!IS_ERR(__k)) wake_up_process(__k); __k; })
/*36*/ int kthread_stop(struct task_struct * a);
/*37*/ int kthread_should_stop();

#endif

#ifndef __LINUX_WORKQUEUE_H__
#define __LINUX_WORKQUEUE_H__

/*0*/ #include <asm-generic/atomic-long.h>
/*0*/ #include <linux/workqueue.h>
/*0*/ struct work_struct;
/*0*/ struct atomic64_t;
/*0*/ #include <linux/types.h>
/*0*/ struct workqueue_struct;
/*0*/ struct lock_class_key;
/*0*/ struct timer_list;
/*8*/ #include <linux/timer.h>
/*10*/ #include <linux/bitops.h>
/*11*/ #include <linux/lockdep.h>
/*18*/ typedef void (*work_func_t)(struct work_struct *);
/*77*/ enum _home_enight_linux_322_include_linux_workqueueh_77 {WORK_STRUCT_PENDING_BIT = 0, WORK_STRUCT_DELAYED_BIT = 1, WORK_STRUCT_CWQ_BIT = 2, WORK_STRUCT_LINKED_BIT = 3, WORK_STRUCT_COLOR_SHIFT = 4, WORK_STRUCT_COLOR_BITS = 4, WORK_STRUCT_PENDING = 1, WORK_STRUCT_DELAYED = 2, WORK_STRUCT_CWQ = 4, WORK_STRUCT_LINKED = 8, WORK_STRUCT_STATIC = 0, WORK_NR_COLORS = 15, WORK_NO_COLOR = 15, WORK_CPU_UNBOUND = 64, WORK_CPU_NONE = 65, WORK_CPU_LAST = 65, WORK_STRUCT_FLAG_BITS = 8, WORK_STRUCT_FLAG_MASK = 255, WORK_STRUCT_WQ_DATA_MASK = -256, WORK_STRUCT_NO_CPU = 16640, WORK_BUSY_PENDING = 1, WORK_BUSY_RUNNING = 2, };;
/*86*/ struct work_struct { atomic_long_t data; struct list_head entry; work_func_t func; };
/*88*/ #define WORK_DATA_INIT() ATOMIC_LONG_INIT(WORK_STRUCT_NO_CPU)
/**95**/ struct delayed_work {
	struct work_struct work;
	struct timer_list timer;
};
/*135*/ #define DECLARE_WORK(n,f) struct work_struct n = __WORK_INITIALIZER(n, f)
/*147*/ #define PREPARE_WORK(_work,_func) do { (_work)->func = (_func); } while (0)
/*163*/ void __init_work(struct work_struct * a, int b);
/*187*/ #define __INIT_WORK(_work,_func,_onstack) do { __init_work((_work), _onstack); (_work)->data = (atomic_long_t) WORK_DATA_INIT(); INIT_LIST_HEAD(&(_work)->entry); PREPARE_WORK((_work), (_func)); } while (0)
/*196*/ #define INIT_WORK(_work,_func) do { __INIT_WORK((_work), (_func), 0); } while (0)
/*206*/ #define INIT_DELAYED_WORK(_work,_func) do { INIT_WORK(&(_work)->work, (_func)); init_timer(&(_work)->timer); } while (0)
/*301*/ struct workqueue_struct * __alloc_workqueue_key(const char * a, unsigned int b, int c, struct lock_class_key * d, const char * e);
/*318*/ #define alloc_workqueue(name,flags,max_active) __alloc_workqueue_key((name), (flags), (max_active), NULL, NULL)
/*347*/ void destroy_workqueue(struct workqueue_struct * a);
/*349*/ int queue_work(struct workqueue_struct * a, struct work_struct * b);
/*363*/ int schedule_delayed_work(struct delayed_work * a, unsigned long b);
/*371*/ bool flush_work(struct work_struct * a);
/*377*/ bool cancel_delayed_work_sync(struct delayed_work * a);

#endif

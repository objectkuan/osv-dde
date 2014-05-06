#ifndef __LINUX_FREEZER_H__
#define __LINUX_FREEZER_H__

/*0*/ struct task_struct;
/*6*/ #include <linux/sched.h>
/*7*/ #include <linux/wait.h>
/*24*/ int freezing(struct task_struct * a);
/*62*/ int try_to_freeze();
/*126*/ void set_freezable();

#endif

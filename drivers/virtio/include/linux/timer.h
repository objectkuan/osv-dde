#ifndef __LINUX_TIMER_H__
#define __LINUX_TIMER_H__

/*4*/ #include <linux/list.h>
/*6*/ #include <linux/stddef.h>
/*8*/ #include <linux/stringify.h>
/**34**/ struct timer_list {
    void (*function)(unsigned long);
    unsigned long data;
};
/*93*/ void init_timer_key(struct timer_list * a, const char * b, struct lock_class_key * c);
/*137*/ #define init_timer(timer) init_timer_key((timer), NULL, NULL)

#endif

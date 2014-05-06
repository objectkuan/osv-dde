#ifndef __LINUX_MM_TYPES_H__
#define __LINUX_MM_TYPES_H__

/*0*/ struct atomic_t;
/*5*/ #include <linux/types.h>
/*7*/ #include <linux/list.h>
/*8*/ #include <linux/spinlock.h>
/*10*/ #include <linux/rbtree.h>
/*11*/ #include <linux/rwsem.h>
/*12*/ #include <linux/completion.h>
/*13*/ #include <linux/cpumask.h>
/**152**/ struct page {
    unsigned long private;
    void *ptr;
};

#endif

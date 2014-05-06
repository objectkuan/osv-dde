#ifndef __LINUX_COMPLETION_H__
#define __LINUX_COMPLETION_H__

/*11*/ #include <linux/wait.h>
/**28**/ struct completion {
};
/*44*/ #define DECLARE_COMPLETION(work) struct completion work = COMPLETION_INITIALIZER(work)
/*77*/ void init_completion(struct completion * a);
/*79*/ void wait_for_completion(struct completion * a);
/*91*/ void complete(struct completion * a);

#endif

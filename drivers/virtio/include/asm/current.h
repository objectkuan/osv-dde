#ifndef __ASM_CURRENT_H__
#define __ASM_CURRENT_H__

/*15*/ struct task_struct * get_current();
/*17*/ #define current get_current()

#endif

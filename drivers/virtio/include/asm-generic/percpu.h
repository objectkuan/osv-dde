#ifndef __ASM_GENERIC_PERCPU_H__
#define __ASM_GENERIC_PERCPU_H__

/*6*/ #include <linux/percpu-defs.h>
/*18*/ extern unsigned long __per_cpu_offset[64];
/*20*/ #define per_cpu_offset(x) (__per_cpu_offset[x])
/*45*/ #define SHIFT_PERCPU_PTR(__p,__offset) ({ __verify_pcpu_ptr((__p)); RELOC_HIDE((typeof(*(__p)) __kernel __force *)(__p), (__offset)); })
/*65*/ #define this_cpu_ptr(ptr) ptr

#endif

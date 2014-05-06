#ifndef __LINUX_PERCPU_DEFS_H__
#define __LINUX_PERCPU_DEFS_H__

/*26*/ #define __verify_pcpu_ptr(ptr) do { const void __percpu *__vpp_verify = (typeof(ptr))NULL; (void)__vpp_verify; } while (0)

#endif

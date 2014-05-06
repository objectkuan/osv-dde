#ifndef __LINUX_PERCPU_H__
#define __LINUX_PERCPU_H__

/*6*/ #include <linux/cpumask.h>
/*148*/ #define per_cpu_ptr(ptr,cpu) SHIFT_PERCPU_PTR((ptr), per_cpu_offset((cpu)))
/*161*/ void * __alloc_percpu(size_t a, size_t b);
/*162*/ void free_percpu(void * a);
/*165*/ #define alloc_percpu(type) (typeof(type) __percpu *)__alloc_percpu(sizeof(type), __alignof__(type))

#endif

#ifndef __LINUX_KERNEL_H__
#define __LINUX_KERNEL_H__

/*7*/ #define __ALIGN_KERNEL(x,a) __ALIGN_KERNEL_MASK(x, (typeof(x))(a) - 1)
/*8*/ #define __ALIGN_KERNEL_MASK(x,mask) (((x) + (mask)) & ~(mask))
/*14*/ #include <linux/stddef.h>
/*15*/ #include <linux/types.h>
/*17*/ #include <linux/bitops.h>
/*19*/ #include <linux/typecheck.h>
/*20*/ #include <linux/printk.h>
/*23*/ #include <asm/bug.h>
/*40*/ #define ALIGN(x,a) __ALIGN_KERNEL((x), (a))
/*45*/ #define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]) + __must_be_array(arr))
/*189*/ void panic(const char * a, ...);
/*303*/ int sprintf(char * a, const char * b, ...);
/*306*/ int snprintf(char * a, size_t b, const char * c, ...);
/*536*/ #define min(x,y) ({ typeof(x) _min1 = (x); typeof(y) _min2 = (y); (void) (&_min1 == &_min2); _min1 < _min2 ? _min1 : _min2; })
/*659*/ #define container_of(ptr,type,member) ({ const typeof( ((type *)0)->member ) *__mptr = (ptr); (type *)( (char *)__mptr - offsetof(type,member) );})
/*678*/ #define BUILD_BUG_ON_ZERO(e) (sizeof(struct { int:-!!(e); }))
/*697*/ #define BUILD_BUG_ON(condition) ((void)sizeof(char[1 - 2*!!(condition)]))
/**751**/ struct sysinfo {
	unsigned long freeram;
	unsigned long totalram;
};

#endif

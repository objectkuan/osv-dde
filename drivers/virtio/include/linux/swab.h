#ifndef __LINUX_SWAB_H__
#define __LINUX_SWAB_H__

/*4*/ #include <linux/types.h>
/*12*/ #define ___constant_swab16(x) ((__u16)( (((__u16)(x) & (__u16)0x00ffU) << 8) | (((__u16)(x) & (__u16)0xff00U) >> 8)))
/*53*/ __u16 __fswab16(__u16 a);
/*99*/ #define __swab16(x) (__builtin_constant_p((__u16)(x)) ? ___constant_swab16(x) : __fswab16(x))

#endif

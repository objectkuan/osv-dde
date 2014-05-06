#ifndef __ASM_GENERIC_ATOMIC_LONG_H__
#define __ASM_GENERIC_ATOMIC_LONG_H__

/*0*/ #include <linux/types.h>
/*23*/ typedef atomic64_t atomic_long_t;
/*25*/ #define ATOMIC_LONG_INIT(i) ATOMIC64_INIT(i)

#endif

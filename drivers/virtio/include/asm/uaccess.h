#ifndef __ASM_UACCESS_H__
#define __ASM_UACCESS_H__

/*6*/ #include <linux/errno.h>
/*10*/ #include <asm/asm.h>
/*432*/ #define __m(x) (*(struct __large_struct __user *)(x))
/*490*/ #define __get_user(x,ptr) __get_user_nocheck((x), (ptr), sizeof(*(ptr)))

#endif

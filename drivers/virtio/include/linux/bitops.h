#ifndef __LINUX_BITOPS_H__
#define __LINUX_BITOPS_H__

/*10*/ #define BITS_TO_LONGS(nr) DIV_ROUND_UP(nr, BITS_PER_BYTE * sizeof(long))
/*22*/ #include <asm/bitops.h>

#endif

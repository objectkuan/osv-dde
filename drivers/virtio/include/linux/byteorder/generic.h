#ifndef __LINUX_BYTEORDER_GENERIC_H__
#define __LINUX_BYTEORDER_GENERIC_H__

/*87*/ #define cpu_to_le32 __cpu_to_le32
/*136*/ #define ___ntohs(x) __be16_to_cpu(x)
/*141*/ #define ntohs(x) ___ntohs(x)

#endif

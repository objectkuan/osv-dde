#ifndef __LINUX_BYTEORDER_LITTLE_ENDIAN_H__
#define __LINUX_BYTEORDER_LITTLE_ENDIAN_H__

/*5*/ #define __LITTLE_ENDIAN 1234
/*11*/ #include <linux/types.h>
/*12*/ #include <linux/swab.h>
/*32*/ #define __cpu_to_le32(x) ((__force __le32)(__u32)(x))
/*41*/ #define __be16_to_cpu(x) __swab16((__force __u16)(__be16)(x))
/*105*/ #include <linux/byteorder/generic.h>

#endif

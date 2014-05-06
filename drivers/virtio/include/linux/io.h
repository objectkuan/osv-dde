#ifndef __LINUX_IO_H__
#define __LINUX_IO_H__

/*21*/ #include <linux/types.h>
/*22*/ #include <asm/io.h>
/*62*/ void * devm_ioremap(struct device * a, resource_size_t b, unsigned long c);

#endif

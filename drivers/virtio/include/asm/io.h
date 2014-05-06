#ifndef __ASM_IO_H__
#define __ASM_IO_H__

/*0*/ #include <linux/types.h>
/*53*/ unsigned char readb(const volatile void * a);
/*55*/ unsigned int readl(const volatile void * a);
/*61*/ void writeb(unsigned char a, volatile void * b);
/*63*/ void writel(unsigned int a, volatile void * b);
/*114*/ phys_addr_t virt_to_phys(volatile void * a);
/*132*/ void * phys_to_virt(phys_addr_t a);
/*193*/ #include <asm-generic/iomap.h>

#endif

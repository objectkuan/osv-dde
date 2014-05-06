#ifndef __ASM_SYSTEM_H__
#define __ASM_SYSTEM_H__

/*4*/ #include <asm/asm.h>
/*10*/ #include <linux/kernel.h>
/*422*/ #define mb() asm volatile("mfence":::"memory")
/*482*/ #define smp_mb() mb()
/*486*/ #define smp_rmb() barrier()
/*491*/ #define smp_wmb() barrier()

#endif

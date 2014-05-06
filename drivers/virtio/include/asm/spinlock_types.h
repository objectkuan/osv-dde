#ifndef __ASM_SPINLOCK_TYPES_H__
#define __ASM_SPINLOCK_TYPES_H__

/*0*/ #include <asm/spinlock_types.h>
/*0*/ struct __raw_tickets;
/*0*/ #include <asm-generic/int-ll64.h>
/*8*/ #include <linux/types.h>
/*12*/ typedef u16 __ticketpair_t;
/**26**/ struct __raw_tickets {
};
/*28*/ typedef struct arch_spinlock arch_spinlock_t;
/*28*/ struct arch_spinlock { void *priv; };
/*30*/ #define __ARCH_SPIN_LOCK_UNLOCKED { 0 }

#endif

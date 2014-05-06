#ifndef __ASM_BITOPS_H__
#define __ASM_BITOPS_H__

/*71*/ void set_bit(unsigned int a, volatile unsigned long * b);
/*109*/ void clear_bit(int a, volatile unsigned long * b);
/*313*/ int constant_test_bit(unsigned int a, const volatile unsigned long * b);
/*325*/ int variable_test_bit(int a, const volatile unsigned long * b);
/*336*/ #define test_bit(nr,addr) (__builtin_constant_p((nr)) ? constant_test_bit((nr), (addr)) : variable_test_bit((nr), (addr)))

#endif

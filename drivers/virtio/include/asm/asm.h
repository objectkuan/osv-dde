#ifndef __ASM_ASM_H__
#define __ASM_ASM_H__

/*9*/ #define __ASM_FORM(x) " " #x " "
/*11*/ #define __ASM_EX_SEC " .section __ex_table,\"a\"\n"
/*17*/ #define __ASM_SEL(a,b) __ASM_FORM(b)
/*24*/ #define _ASM_PTR __ASM_SEL(.long, .quad)
/*25*/ #define _ASM_ALIGN __ASM_SEL(.balign 4, .balign 8)
/*51*/ #define _ASM_EXTABLE(from,to) __ASM_EX_SEC _ASM_ALIGN "\n" _ASM_PTR #from "," #to "\n" " .previous\n"

#endif

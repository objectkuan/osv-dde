#ifndef __ASM_GENERIC_BUG_H__
#define __ASM_GENERIC_BUG_H__

/*53*/ #define BUG_ON(condition) do { if (unlikely(condition)) BUG(); } while(0)

#endif

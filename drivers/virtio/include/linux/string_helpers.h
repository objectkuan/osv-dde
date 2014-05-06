#ifndef __LINUX_STRING_HELPERS_H__
#define __LINUX_STRING_HELPERS_H__

/*4*/ #include <linux/types.h>
/*11*/ enum string_size_units {STRING_UNITS_10 = 0, STRING_UNITS_2 = 1, };;
/*14*/ int string_get_size(u64 a, enum string_size_units b, char * c, int d);

#endif

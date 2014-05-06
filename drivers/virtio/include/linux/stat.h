#ifndef __LINUX_STAT_H__
#define __LINUX_STAT_H__

/*33*/ #define S_IRUSR 00400
/*34*/ #define S_IWUSR 00200
/*38*/ #define S_IRGRP 00040
/*43*/ #define S_IROTH 00004
/*52*/ #define S_IRUGO (S_IRUSR|S_IRGRP|S_IROTH)
/*59*/ #include <linux/types.h>

#endif

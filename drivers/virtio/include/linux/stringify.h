#ifndef __LINUX_STRINGIFY_H__
#define __LINUX_STRINGIFY_H__

/*9*/ #define __stringify_1(x...) #x
/*10*/ #define __stringify(x...) __stringify_1(x)

#endif

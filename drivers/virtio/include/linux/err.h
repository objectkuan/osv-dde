#ifndef __LINUX_ERR_H__
#define __LINUX_ERR_H__

/*25*/ void * ERR_PTR(long a);
/*30*/ long PTR_ERR(const void * a);
/*35*/ long IS_ERR(const void * a);

#endif

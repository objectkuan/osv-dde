#ifndef __LINUX_HDREG_H__
#define __LINUX_HDREG_H__

/*4*/ #include <linux/types.h>
/**328**/ struct hd_geometry {
	unsigned char heads;
	unsigned char sectors;
	unsigned short cylinders;
};

#endif

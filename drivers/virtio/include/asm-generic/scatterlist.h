#ifndef __ASM_GENERIC_SCATTERLIST_H__
#define __ASM_GENERIC_SCATTERLIST_H__

/*4*/ #include <linux/types.h>
/**17**/ struct scatterlist {
    void *buf;
	unsigned int length;
};

#endif

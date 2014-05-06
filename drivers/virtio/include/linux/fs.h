#ifndef __LINUX_FS_H__
#define __LINUX_FS_H__

/*11*/ #include <linux/blk_types.h>
/*12*/ #include <linux/types.h>
/*158*/ #define RW_MASK REQ_WRITE
/*162*/ #define WRITE RW_MASK
/*380*/ #include <linux/wait.h>
/*381*/ #include <linux/kdev_t.h>
/*384*/ #include <linux/stat.h>
/*386*/ #include <linux/list.h>
/*391*/ #include <linux/mutex.h>
/**694**/ struct block_device {
	struct gendisk * bd_disk;
};
/*1098*/ typedef struct files_struct * fl_owner_t;
/*1574*/ typedef int (*filldir_t)(void *, const char *, int, loff_t, u64, unsigned int);
/*2086*/ int register_blkdev(unsigned int a, const char * b);
/*2087*/ void unregister_blkdev(unsigned int a, const char * b);
/*2326*/ #include <linux/err.h>

#endif

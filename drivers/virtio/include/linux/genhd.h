#ifndef __LINUX_GENHD_H__
#define __LINUX_GENHD_H__

/*0*/ struct hd_struct;
/*0*/ #include <linux/genhd.h>
/*12*/ #include <linux/types.h>
/*13*/ #include <linux/kdev_t.h>
/*15*/ #include <linux/slab.h>
/*20*/ #define dev_to_disk(device) container_of((device), struct gendisk, part0.__dev)
/*22*/ #define disk_to_dev(disk) (&(disk)->part0.__dev)
/*63*/ #include <linux/device.h>
/*66*/ #include <linux/fs.h>
/*67*/ #include <linux/workqueue.h>
/**120**/ struct hd_struct {
	struct device __dev;
};
/**194**/ struct gendisk {
	struct request_queue * queue;
	void * private_data;
	struct hd_struct part0;
	char disk_name[32];
	int major;
	int first_minor;
	const struct block_device_operations * fops;
	struct device * driverfs_dev;
    void *cppdev;
};
/*410*/ void add_disk(struct gendisk * a);
/*411*/ void del_gendisk(struct gendisk * a);
/*416*/ void set_disk_ro(struct gendisk * a, int b);
/*439*/ sector_t get_capacity(struct gendisk * a);
/*443*/ void set_capacity(struct gendisk * a, sector_t b);
/*609*/ struct gendisk * alloc_disk(int a);
/*611*/ void put_disk(struct gendisk * a);

#endif

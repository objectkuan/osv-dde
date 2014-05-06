#ifndef __LINUX_IDR_H__
#define __LINUX_IDR_H__

/*0*/ struct idr;
/*0*/ #include <linux/idr.h>
/*15*/ #include <linux/types.h>
/*16*/ #include <linux/bitops.h>
/**65**/ struct idr {
	struct idr_layer * top;
	struct idr_layer * id_free;
	int layers;
	int id_free_cnt;
	spinlock_t lock;
};
/*67*/ #define IDR_INIT(name) { .top = NULL, .id_free = NULL, .layers = 0, .id_free_cnt = 0, .lock = __SPIN_LOCK_UNLOCKED(name.lock), }
/**137**/ struct ida {
	struct idr idr;
	struct ida_bitmap * free_bitmap;
};
/*139*/ #define IDA_INIT(name) { .idr = IDR_INIT(name), .free_bitmap = NULL, }
/*140*/ #define DEFINE_IDA(name) struct ida name = IDA_INIT(name)
/*150*/ int ida_simple_get(struct ida * a, unsigned int b, unsigned int c, gfp_t d);
/*151*/ void ida_simple_remove(struct ida * a, unsigned int b);

#endif

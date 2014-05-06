#ifndef __LINUX_BLKDEV_H__
#define __LINUX_BLKDEV_H__

#ifndef __cplusplus
/*0*/ struct rb_node;
/*0*/ #include <linux/rbtree.h>
/*0*/ struct _home_enight_linux_322_include_linux_blkdevh_122;
/*0*/ #include <linux/blkdev.h>
/*0*/ struct scatterlist;
/*0*/ #include <asm-generic/scatterlist.h>
/*0*/ #include <linux/types.h>
/*6*/ #include <linux/sched.h>
/*8*/ #include <linux/genhd.h>
/*9*/ #include <linux/list.h>
/*10*/ #include <linux/timer.h>
/*11*/ #include <linux/workqueue.h>
/*14*/ #include <linux/wait.h>
/*15*/ #include <linux/mempool.h>
/*16*/ #include <linux/bio.h>
/*17*/ #include <linux/stringify.h>
/*18*/ #include <linux/gfp.h>
#endif /* ! __cpluscplus */

/*71*/ enum rq_cmd_type_bits {REQ_TYPE_FS = 1, REQ_TYPE_BLOCK_PC = 2, REQ_TYPE_SENSE = 3, REQ_TYPE_PM_SUSPEND = 4, REQ_TYPE_PM_RESUME = 5, REQ_TYPE_PM_SHUTDOWN = 6, REQ_TYPE_SPECIAL = 7, REQ_TYPE_ATA_TASKFILE = 8, REQ_TYPE_ATA_PC = 9, };;
/**175**/ struct request {
	enum rq_cmd_type_bits cmd_type;
	unsigned int cmd_flags;
    unsigned char * buf;
	unsigned char * cmd;
    unsigned long __sector;
    unsigned long __data_len;
	unsigned int resid_len;
	unsigned int sense_len;
	int errors;
	unsigned short cmd_len;
	void * sense;
	unsigned short nr_phys_segments;

    void *bio;
    struct request *next, *prev;
};

#ifndef __cplusplus
/*180*/ unsigned short req_get_ioprio(struct request * a);
/*197*/ typedef void (request_fn_proc)(struct request_queue *);
/**390**/ struct request_queue {
    request_fn_proc *request_fn;
    spinlock_t *queue_lock;
	void * queuedata;
};
/*516*/ #define rq_data_dir(rq) ((rq)->cmd_flags & 1)
/*593*/ #define BLK_BOUNCE_ANY (-1ULL)
/*658*/ void blk_put_request(struct request * a);
/*662*/ struct request * blk_make_request(struct request_queue * a, struct bio * b, gfp_t c);
/*680*/ int scsi_cmd_blk_ioctl(struct block_device * a, fmode_t b, unsigned int c, void * d);
/*707*/ void blk_start_queue(struct request_queue * a);
/*708*/ void blk_stop_queue(struct request_queue * a);
/*723*/ int blk_execute_rq(struct request_queue * a, struct gendisk * b, struct request * c, int d);
/*743*/ sector_t blk_rq_pos(const struct request * a);
/*770*/ struct request * blk_peek_request(struct request_queue * a);
/*771*/ void blk_start_request(struct request * a);
/*796*/ void __blk_end_request_all(struct request * a, int b);
/*811*/ struct request_queue * blk_init_queue(request_fn_proc * a, spinlock_t * b);
/*814*/ void blk_cleanup_queue(struct request_queue * a);
/*816*/ void blk_queue_bounce_limit(struct request_queue * a, u64 b);
/*818*/ void blk_queue_max_hw_sectors(struct request_queue * a, unsigned int b);
/*819*/ void blk_queue_max_segments(struct request_queue * a, unsigned short b);
/*820*/ void blk_queue_max_segment_size(struct request_queue * a, unsigned int b);
/*823*/ void blk_queue_logical_block_size(struct request_queue * a, unsigned short b);
/*824*/ void blk_queue_physical_block_size(struct request_queue * a, unsigned int b);
/*826*/ void blk_queue_alignment_offset(struct request_queue * a, unsigned int b);
/*828*/ void blk_queue_io_min(struct request_queue * a, unsigned int b);
/*830*/ void blk_queue_io_opt(struct request_queue * a, unsigned int b);
/*854*/ void blk_queue_flush(struct request_queue * a, unsigned int b);
/*858*/ int blk_rq_map_sg(struct request_queue * a, struct request * b, struct scatterlist * c);
/*1014*/ unsigned short queue_logical_block_size(struct request_queue * a);
/**1318**/ struct block_device_operations {
	int (*ioctl)(struct block_device *, fmode_t, unsigned int, unsigned long);
	struct module * owner;
	int (*getgeo)(struct block_device *, struct hd_geometry *);
};
#endif /* ! __cpluscplus */

#endif

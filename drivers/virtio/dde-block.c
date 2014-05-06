#include <linux/genhd.h>
#include <linux/blkdev.h>
#include <linux/slub_def.h>

#include "dde.h"
#include "dde-block.h"

struct gendisk *alloc_disk(int minors) {
    struct gendisk *gd = kmalloc(sizeof(struct gendisk), GFP_KERNEL);
    if (gd) {
        gd->cppdev = dde_get_blk_cppdev();
    }
	return gd;
}

struct request_queue *blk_init_queue(request_fn_proc *rfn, spinlock_t *lock) {
    struct request_queue *ret = kmalloc(sizeof(struct request_queue), GFP_KERNEL);
    if (ret) {
        ret->request_fn = rfn;
        ret->queue_lock = lock;
    }
	return ret;
}

void add_disk(struct gendisk *disk) {
    dde_add_disk(disk);
}

void set_capacity(struct gendisk * gd, sector_t size) {
    dde_set_capacity(gd->cppdev, size);
}

struct request *blk_peek_request(struct request_queue *queue) {
	return dde_fetch_request();
}

void blk_start_queue(struct request_queue *queue) {
    /* Nothing to do as we never disable the queue... */
}

void blk_start_request(struct request *req) {
    dde_dequeue_request(req);
}

void __blk_end_request_all(struct request *req, int error) {
    req->errors = error;
    dde_finish_request(req);
}

sector_t blk_rq_pos(const struct request *req) {
    return req->__sector;
}

unsigned short req_get_ioprio(struct request *a) {
	return 0;
}

const size_t page_size = 0x1000;

int blk_rq_map_sg(struct request_queue *rq, struct request *req, struct scatterlist *sg) {
    int nr_blocks = 0;
    size_t len = 0;
    size_t offset = (size_t)(req->buf) & (page_size - 1);
    unsigned char *base = req->buf;

    while (len != req->__data_len) {
        size_t size = req->__data_len - len;
        if (size > page_size)
            size = page_size;
        if (offset + size > page_size)
            size = page_size - offset;
        len += size;

        sg_set_buf(sg, base, size);

        base += size;
        sg = sg_next(sg);
        offset = 0;
        nr_blocks ++;
    }

	return nr_blocks;
}

void dde_blk_start_xmit(void *gendisk) {
    struct gendisk *gd = (struct gendisk *)gendisk;
    struct request_queue *queue = gd->queue;
    queue->request_fn(queue);
}

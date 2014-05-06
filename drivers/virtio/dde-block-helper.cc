#include "dde-block.h"

#include "mempool.hh"
#include <api/stdlib.h>
#include <osv/bio.h>
#include <osv/condvar.h>

#include "drivers/virtio-blk.hh"
#include <linux/blkdev.h>

void dde_add_disk(void *gd) {
    virtio::blk::current_disk()->add_disk(gd);
}

void dde_set_capacity(void *cppdev, unsigned long nr_sects) {
    virtio::blk *drv = reinterpret_cast<virtio::blk*>(cppdev);
    drv->set_capacity(nr_sects);
}

void *dde_get_blk_cppdev(void)
{
    return virtio::blk::current_disk();
}

struct request *dde_fetch_request(void)
{
    virtio::blk *blk = virtio::blk::current_disk();
    return blk->get_request();
}

void dde_dequeue_request(struct request *req)
{
    virtio::blk *blk = virtio::blk::current_disk();
    return blk->dequeue_request(req);
}

void dde_finish_request(struct request *req)
{
    virtio::blk *blk = virtio::blk::current_disk();
    return blk->finish_request(req);
}

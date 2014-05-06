/*
 * Copyright (C) 2013 Cloudius Systems, Ltd.
 *
 * This work is open source software, licensed under the terms of the
 * BSD license as described in the LICENSE file in the top-level directory.
 */


#include <sys/cdefs.h>

#include "drivers/virtio.hh"
#include "drivers/virtio-blk.hh"
#include "drivers/pci-device.hh"
#include "interrupt.hh"

#include "mempool.hh"
#include "mmu.hh"

#include <api/stdlib.h>
#include <string>
#include <string.h>
#include <map>
#include <errno.h>
#include <osv/debug.h>

#include "sched.hh"
#include "irqlock.hh"
#include "osv/trace.hh"
#include "drivers/clock.hh"
#include "drivers/clockevent.hh"

#include <osv/device.h>
#include <osv/bio.h>

#include "dde.h"
#include "dde-block.h"
#include <linux/blkdev.h>

using namespace memory;


namespace virtio {

static const int sector_size = 512;

static void *registered_gd = 0;
static blk *block = 0;

int blk::_instance = 0;

struct blk_priv {
    blk* drv;
};

static void
blk_strategy(struct bio *bio)
{
    struct blk_priv *prv = reinterpret_cast<struct blk_priv*>(bio->bio_dev->private_data);

    bio->bio_offset += bio->bio_dev->offset;
    prv->drv->make_request(bio);
}

static int
blk_read(struct device *dev, struct uio *uio, int ioflags)
{
    return bdev_read(dev, uio, ioflags);
}

static int
blk_write(struct device *dev, struct uio *uio, int ioflags)
{
    return bdev_write(dev, uio, ioflags);
}

static struct devops blk_devops {
    no_open,
    no_close,
    blk_read,
    blk_write,
    no_ioctl,
    no_devctl,
    blk_strategy,
};

struct driver blk_driver = {
    "virtio_blk",
    &blk_devops,
    sizeof(struct blk_priv),
};

static void
req_list_add(struct request *req, struct request *&head) {
    if (head == 0) {
        head = req;
        req->prev = req->next = req;
    } else {
        req->prev = head->prev;
        req->next = head;
        req->prev->next = req->next->prev = req;
    }
}

static void
req_list_remove(struct request *req, struct request *&head) {
    req->prev->next = req->next;
    req->next->prev = req->prev;

    if (head == req)
        head = req->next;
    if (head == req)
        head = 0;
}

blk *blk::current_disk() {
    return block ? block : reinterpret_cast<blk *>(current);
}

void blk::add_disk(void *gd) {
    registered_gd = gd;
}

blk::blk(pci::device& pci_dev)
    : virtio_driver(pci_dev), _req_head(0), _finished_req_head(0)
{
    virtio_w("virtio block driver loaded");
    _driver_name = "virtio-blk";

    if (registered_gd) {
        struct blk_priv* prv;
        struct device *dev;
        std::string dev_name("vblk");
        dev_name += std::to_string(_disk_idx++);

        cleanup_thread = new sched::thread([this] { this->cleanup_request(); });
        cleanup_thread->start();

        block = this;

        dev = device_create(&blk_driver, dev_name.c_str(), D_BLK);
        prv = reinterpret_cast<struct blk_priv*>(dev->private_data);
        prv->drv = this;
        prv->drv->_gendisk = registered_gd;
        dev->size = prv->drv->size();
        read_partition_table(dev);

        registered_gd = 0;
    }
}

blk::~blk()
{
    //TODO: In theory maintain the list of free instances and gc it
    // including the thread objects and their stack
    virtio_e("%s called, not implemented", __func__);
}

bool blk::read_config()
{
    virtio_e("%s called, not implemented", __func__);
    return false;
}

void blk::req_done()
{
    virtio_e("%s called, not implemented", __func__);
}

int64_t blk::size()
{
    return _config.capacity * sector_size;
}

int blk::make_request(struct bio* bio)
{
    if (!bio)
        return EIO;

    struct request *req = (struct request *)malloc(sizeof(struct request));
    memset(req, 0, sizeof(struct request));
    /* bio_cmd */
    switch (bio->bio_cmd) {
    case BIO_READ:
    case BIO_WRITE:
    case BIO_FLUSH:
        req->cmd_type = REQ_TYPE_FS;
        break;
    default:
        virtio_e("Unknown bio command: %02x\n", bio->bio_cmd);
        return EIO;
    }
    /* cmd_flags */
    if (bio->bio_cmd == BIO_WRITE)
        req->cmd_flags |= (1 << 0);
    if (bio->bio_cmd == BIO_FLUSH)
        req->cmd_flags |= (1 << 11);
    /* buf */
    req->buf = (unsigned char *)bio->bio_data;
    /* __sector */
    assert(bio->bio_offset % sector_size == 0);
    req->__sector = bio->bio_offset / sector_size;
    /* __data_len */
    req->__data_len = bio->bio_bcount;
    /* misc */
    req->bio = bio;

    WITH_LOCK(_lock) {
        req_list_add(req, _req_head);
    }
    dde_blk_start_xmit(_gendisk);
    return 0;
}

void blk::cleanup_request(void)
{
    struct request *req = 0;
    while (1) {
        sched::thread::wait_until([this] {
                bool empty;
                irq_save_lock_type irq_lock;
                WITH_LOCK(irq_lock) {
                    sched::preempt_disable();
                    WITH_LOCK(this->_cleanup_lock) {
                        empty = (this->_finished_req_head == 0);
                    }
                    sched::preempt_enable();
                }
                return !empty;
            });

        while ((req = _finished_req_head) != 0) {
            irq_save_lock_type irq_lock;
            WITH_LOCK(irq_lock) {
                sched::preempt_disable();
                WITH_LOCK(_cleanup_lock) {
                    req_list_remove(req, _finished_req_head);
                }
                sched::preempt_enable();
            }

            struct bio *bio = (struct bio *)(req->bio);
            bool ok = (req->errors == 0);
            free(req);
            biodone(bio, ok);
        }
    }
}

u32 blk::get_driver_features(void)
{
    virtio_e("%s called, not implemented", __func__);
    return 0;
}

void blk::dequeue_request(struct request *req)
{
    WITH_LOCK(_lock) {
        req_list_remove(req, _req_head);
    }
}

void blk::finish_request(struct request *req)
{
    WITH_LOCK(_cleanup_lock) {
        req_list_add(req, _finished_req_head);
    }

    cleanup_thread->wake();
}

hw_driver* blk::probe(hw_device* dev)
{
    return virtio::probe<blk, VIRTIO_BLK_DEVICE_ID>(dev);
}

}

/*
 * Copyright (C) 2013 Cloudius Systems, Ltd.
 *
 * This work is open source software, licensed under the terms of the
 * BSD license as described in the LICENSE file in the top-level directory.
 */

#include <string.h>

#include "drivers/virtio.hh"
#include "drivers/virtio-vring.hh"
#include <osv/debug.h>
#include "osv/trace.hh"

#include "dde.h"

using namespace pci;

namespace virtio {

virtio_driver *virtio_driver::current = 0;
int virtio_driver::_disk_idx = 0;

virtio_driver::virtio_driver(pci::device& dev)
    : _dev(dev), _msi(&dev)
{
    current = this;

    parse_pci_config();

    int r;
    struct pci_dev *pcidev = dde_alloc_pci_dev(
        dev.get_device_id(), dev.get_revision_id(),
        dev.get_subsystem_vid(), dev.get_subsystem_id(),
        dev.get_interrupt_line(), &dev);
    if ((r = dde_pci_probe(pcidev)) < 0)
        virtio_e("Driver initialization failed, errno = %d", r);
}

virtio_driver::~virtio_driver()
{
}

bool virtio_driver::setup_features(void)
{
    virtio_e("%s called, not implemented", __func__);
    return false;
}

void virtio_driver::dump_config()
{
    u8 B, D, F;
    _dev.get_bdf(B, D, F);

    _dev.dump_config();
    virtio_i("%s [%x:%x.%x] vid:id= %x:%x subsystem vid:id= %x:%x",
             get_name().c_str(),
             (u16)B, (u16)D, (u16)F,
             _dev.get_vendor_id(),
             _dev.get_device_id(),
             _dev.get_subsystem_vid(),
             _dev.get_subsystem_id());
}

bool virtio_driver::parse_pci_config(void)
{
    _dev.parse_pci_config();
    return true;
}

void virtio_driver::reset_host_side()
{
    virtio_e("%s called, not implemented", __func__);
}

void virtio_driver::free_queues(void)
{
    virtio_e("%s called, not implemented", __func__);
}

bool virtio_driver::kick(int queue)
{
    virtio_e("%s called, not implemented", __func__);
    return false;
}

bool virtio_driver::probe_virt_queues(void)
{
    virtio_e("%s called, not implemented", __func__);
    return false;
}

vring* virtio_driver::get_virt_queue(unsigned idx)
{
    virtio_e("%s called, not implemented", __func__);
    return NULL;
}

void virtio_driver::wait_for_queue(vring* queue, bool (vring::*pred)() const)
{
    virtio_e("%s called, not implemented", __func__);
}

u32 virtio_driver::get_device_features(void)
{
    virtio_e("%s called, not implemented", __func__);
    return 0;
}

bool virtio_driver::get_device_feature_bit(int bit)
{
    virtio_e("%s called, not implemented", __func__);
    return false;
}

void virtio_driver::set_guest_features(u32 features)
{
    virtio_e("%s called, not implemented", __func__);
}

void virtio_driver::set_guest_feature_bit(int bit, bool on)
{
    virtio_e("%s called, not implemented", __func__);
}

u32 virtio_driver::get_guest_features(void)
{
    virtio_e("%s called, not implemented", __func__);
    return 0;
}

bool virtio_driver::get_guest_feature_bit(int bit)
{
    virtio_e("%s called, not implemented", __func__);
    return false;
}


u8 virtio_driver::get_dev_status(void)
{
    virtio_e("%s called, not implemented", __func__);
    return 0;
}

void virtio_driver::set_dev_status(u8 status)
{
    virtio_e("%s called, not implemented", __func__);
}

void virtio_driver::add_dev_status(u8 status)
{
    virtio_e("%s called, not implemented", __func__);
}

void virtio_driver::del_dev_status(u8 status)
{
    virtio_e("%s called, not implemented", __func__);
}

bool virtio_driver::get_virtio_config_bit(u32 offset, int bit)
{
    virtio_e("%s called, not implemented", __func__);
    return false;
}

void virtio_driver::set_virtio_config_bit(u32 offset, int bit, bool on)
{
    virtio_e("%s called, not implemented", __func__);
}

void virtio_driver::virtio_conf_write(u32 offset, void* buf, int length)
{
    virtio_e("%s called, not implemented", __func__);
}

void virtio_driver::virtio_conf_read(u32 offset, void* buf, int length)
{
    virtio_e("%s called, not implemented", __func__);
}

}

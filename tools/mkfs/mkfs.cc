/*
 * Copyright (C) 2013 Cloudius Systems, Ltd.
 *
 * This work is open source software, licensed under the terms of the
 * BSD license as described in the LICENSE file in the top-level directory.
 */

#include <assert.h>
#include <osv/device.h>
#include <osv/run.hh>
#include <fs/vfs/vfs.h>
#include <iostream>

using namespace osv;

extern "C" int osv_zfs_ioctl(unsigned long req, void* buffer);

static int zfs_ioctl(device* dev, ulong req, void* buffer)
{
    return osv_zfs_ioctl(req, buffer);
}

static devops zfs_devops = {
    no_open,
    no_close,
    no_read,
    no_write,
    zfs_ioctl,
    no_devctl,
};

using namespace std;

void mkfs()
{
    auto zfs_driver = new driver;
    zfs_driver->devops = &zfs_devops;
    zfs_driver->devsz = 0;
    zfs_driver->flags = 0;
    zfs_driver->name = "zfs";
    device_create(zfs_driver, "zfs", D_CHR);
    mkdir("/etc", 0755);
    int fd = creat("/etc/mnttab", 0644);
    assert(fd != -1);
    close(fd);

    int ret;
    auto ok = run("/zpool.so",
            {"zpool", "create", "-f", "-R", "/zfs", "osv", "/dev/vblk0.1"}, &ret);
    assert(ok && ret == 0);
    ok = run("/zfs.so", {"zfs", "create", "osv/zfs"}, &ret);
    assert(ok && ret == 0);
}

int main(int ac, char** av)
{
    cout << "Running mkfs...\n";
    mkfs();
    sync();
}


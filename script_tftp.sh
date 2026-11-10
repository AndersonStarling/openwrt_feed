#!/bin/sh

OPENWRT_DIR="/home/ntai/work_dir/openwrt"

# cp $OPENWRT_DIR/bin/targets/omap/generic/openwrt-omap-generic-ti_am335x-bone-black-router-custom-ext4-sdcard.img.gz /home/ntai/work_dir/image
cp $OPENWRT_DIR/bin/targets/omap/generic/openwrt-omap-generic-ti_am335x-bone-black-router-custom-squashfs-sdcard.img.gz /home/ntai/work_dir/image
sync
gunzip -f /home/ntai/work_dir/image/openwrt-omap-generic-ti_am335x-bone-black-router-custom-squashfs-sdcard.img.gz
sync
scp -O /home/ntai/work_dir/image/openwrt-omap-generic-ti_am335x-bone-black-router-custom-squashfs-sdcard.img ntai-laptop@192.168.1.20:/srv/tftp/openwrt.img









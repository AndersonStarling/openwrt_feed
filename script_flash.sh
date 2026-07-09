#!/bin/sh

OPENWRT_DIR="/home/ntai/work_dir/openwrt"

cp $OPENWRT_DIR/bin/targets/omap/generic/openwrt-omap-generic-ti_am335x-bone-black-router-custom-ext4-sdcard.img.gz /home/ntai/work_dir/image

gunzip -f /home/ntai/work_dir/image/openwrt-omap-generic-ti_am335x-bone-black-router-custom-ext4-sdcard.img.gz

sudo dd if=/home/ntai/work_dir/image/openwrt-omap-generic-ti_am335x-bone-black-router-custom-ext4-sdcard.img of=/dev/sdb bs=4M status=progress

sync







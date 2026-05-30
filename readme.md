# OpenWrt BBB Build Guide

This repo provides a helper script to prepare an OpenWrt source tree for the
BeagleBone Black (BBB) build.

## Prerequisites
- Git installed
- Build dependencies for OpenWrt (see the OpenWrt docs)

## Steps
1) Clone OpenWrt and checkout the BBB support branch (openwrt-24.10):
```bash
git clone git clone https://git.openwrt.org/openwrt/openwrt.git openwrt
cd openwrt
git checkout openwrt-24.10
```

2) Run the helper script to update the OpenWrt source build inputs:
```bash
cd /path/to/openwrt_feed
./script.sh
```

What the script does:
- Copies `.config` into `openwrt/.config`
- Copies `files/` into `openwrt/files/`

3) Build OpenWrt:
```bash
cd /path/to/openwrt
make -j$(nproc) V=s | tee build.log
```

## Notes
- Keep your custom `.config` and `files/` updated in this repo, then rerun
	`script.sh` before rebuilding.





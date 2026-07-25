#!/bin/sh

SCRIPT_DIR="/home/ntai/work_dir/openwrt_feed"
OPENWRT_DIR="/home/ntai/work_dir/openwrt"

if [ ! -d "$OPENWRT_DIR" ]; then
	echo "OpenWrt directory not found: $OPENWRT_DIR" >&2
	echo "Set OPENWRT_DIR or place openwrt next to openwrt_feed." >&2
	exit 1
fi

if [ "$SCRIPT_DIR" = "$OPENWRT_DIR" ]; then
	echo "Refusing to copy into the same directory: $OPENWRT_DIR" >&2
	exit 1
fi

# Apply all build system patches
for patch in "$SCRIPT_DIR/patches/build_system_patches/"*.patch; do
	echo "Applying patch: $patch"
	patch -N -p1 -d "$OPENWRT_DIR" < "$patch"
done

# Copy .config and files overlay into the OpenWrt tree.
mkdir -p "$OPENWRT_DIR/files"
cp -a "$SCRIPT_DIR/files/." "$OPENWRT_DIR/files/"

# Copy device tree to the OpenWrt tree.
mkdir -p "$OPENWRT_DIR/target/linux/omap/dts"
cp -a "$SCRIPT_DIR/dts/." "$OPENWRT_DIR/target/linux/omap/dts/"

# Copy kernel config to the OpenWrt tree.
cp -a "$SCRIPT_DIR/kernel_config/config-6.6" "$OPENWRT_DIR/target/linux/omap/config-6.6"

DTS_DST="$OPENWRT_DIR/target/linux/omap/files/arch/arm/boot/dts/ti/omap"
mkdir -p "$DTS_DST"

for f in "$SCRIPT_DIR/dts/"*; do
    echo "Copying $(basename "$f")"
    cp -a "$f" "$DTS_DST/"
done

KERNEL_PATCH_DIR="$OPENWRT_DIR/target/linux/omap/patches-6.6"
for f in "$SCRIPT_DIR/patches/kernel_patches/"*; do
    echo "Copying patch $(basename "$f")"
    cp -a "$f" "$KERNEL_PATCH_DIR/"
done

UBOOT_PATCH_DIR="$OPENWRT_DIR/package/boot/uboot-omap/patches"
mkdir -p "$UBOOT_PATCH_DIR"
for f in "$SCRIPT_DIR/patches/uboot_patches/"*; do
    echo "Copying patch $(basename "$f")"
    cp -a "$f" "$UBOOT_PATCH_DIR/"
done

# update feeds.conf.default
rm "$OPENWRT_DIR/.config"
cp -f "$SCRIPT_DIR/.config" "$OPENWRT_DIR/.config"

cat "$SCRIPT_DIR/default.config" >> "$OPENWRT_DIR/feeds.conf.default"
rm -rf "$OPENWRT_DIR/package/feeds"
"$OPENWRT_DIR/scripts/feeds" update
"$OPENWRT_DIR/scripts/feeds" install -a


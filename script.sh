#!/bin/sh
set -e

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

# Copy .config and files overlay into the OpenWrt tree.
mkdir -p "$OPENWRT_DIR/files"
cp -a "$SCRIPT_DIR/files/." "$OPENWRT_DIR/files/"

# update feeds.conf.default
cat "$SCRIPT_DIR/default.config" >> "$OPENWRT_DIR/feeds.conf.default"
rm -rf "$OPENWRT_DIR/package/feeds"
"$OPENWRT_DIR/scripts/feeds" update
"$OPENWRT_DIR/scripts/feeds" install -a
cp -f "$SCRIPT_DIR/.config" "$OPENWRT_DIR/.config"

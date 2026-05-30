#!/bin/sh
set -e

SCRIPT_DIR="$(CDPATH= cd "$(dirname "$0")" && pwd)"
OPENWRT_DIR="${OPENWRT_DIR:-$SCRIPT_DIR/../openwrt}"

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
cp -f "$SCRIPT_DIR/.config" "$OPENWRT_DIR/.config"
mkdir -p "$OPENWRT_DIR/files"
cp -a "$SCRIPT_DIR/files/." "$OPENWRT_DIR/files/"

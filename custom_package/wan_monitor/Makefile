include $(TOPDIR)/rules.mk

PKG_NAME:=wan-monitor
PKG_VERSION:=1.0
PKG_RELEASE:=1

PKG_BUILD_DIR := $(BUILD_DIR)/$(PKG_NAME)

include $(INCLUDE_DIR)/package.mk

define Package/wan-monitor
  SECTION:=utils
  CATEGORY:=Utilities
  TITLE:=WAN Monitor
endef

define Package/wan-monitor/description
 Simple WAN monitor example.
endef

define Build/Prepare
	mkdir -p $(PKG_BUILD_DIR)/src
	mkdir -p $(PKG_BUILD_DIR)/include
	$(CP) ./src/* $(PKG_BUILD_DIR)/src/
	$(CP) ./include/* $(PKG_BUILD_DIR)/include/
endef

define Build/Compile
	$(TARGET_CC) $(TARGET_CFLAGS) -I$(PKG_BUILD_DIR)/include -c $(PKG_BUILD_DIR)/src/functionality/error/wan_crc_err.c -o $(PKG_BUILD_DIR)/src/functionality/error/wan_crc_err.o
	$(TARGET_CC) $(TARGET_CFLAGS) -I$(PKG_BUILD_DIR)/include -c $(PKG_BUILD_DIR)/src/functionality/error/wan_rx_tx_droped_err.c -o $(PKG_BUILD_DIR)/src/functionality/error/wan_rx_tx_droped_err.o
	$(TARGET_CC) $(TARGET_CFLAGS) -I$(PKG_BUILD_DIR)/include -c $(PKG_BUILD_DIR)/src/functionality/error/wan_rx_tx_err.c -o $(PKG_BUILD_DIR)/src/functionality/error/wan_rx_tx_err.o
	$(TARGET_CC) $(TARGET_CFLAGS) -I$(PKG_BUILD_DIR)/include -c $(PKG_BUILD_DIR)/src/functionality/rtt_packet_loss/wan_rtt_packet_loss.c -o $(PKG_BUILD_DIR)/src/functionality/rtt_packet_loss/wan_rtt_packet_loss.o
	$(TARGET_CC) $(TARGET_CFLAGS) -I$(PKG_BUILD_DIR)/include -c $(PKG_BUILD_DIR)/src/functionality/link/wan_link.c -o $(PKG_BUILD_DIR)/src/functionality/link/wan_link.o
	$(TARGET_CC) $(TARGET_CFLAGS) -I$(PKG_BUILD_DIR)/include -c $(PKG_BUILD_DIR)/src/functionality/speed/wan_speed.c -o $(PKG_BUILD_DIR)/src/functionality/speed/wan_speed.o
	$(TARGET_CC) $(TARGET_CFLAGS) -I$(PKG_BUILD_DIR)/include -c $(PKG_BUILD_DIR)/src/wan_monitor.c -o $(PKG_BUILD_DIR)/src/wan_monitor.o
	$(TARGET_CC) $(TARGET_CFLAGS) -I$(PKG_BUILD_DIR)/include -c $(PKG_BUILD_DIR)/src/ultils/file_handler.c -o $(PKG_BUILD_DIR)/src/ultils/file_handler.o
	$(TARGET_CC) $(TARGET_CFLAGS) -o $(PKG_BUILD_DIR)/wan-monitor \
		                             $(PKG_BUILD_DIR)/src/functionality/error/wan_crc_err.o \
		                             $(PKG_BUILD_DIR)/src/functionality/error/wan_rx_tx_droped_err.o \
		                             $(PKG_BUILD_DIR)/src/functionality/error/wan_rx_tx_err.o \
		                             $(PKG_BUILD_DIR)/src/functionality/rtt_packet_loss/wan_rtt_packet_loss.o \
		                             $(PKG_BUILD_DIR)/src/functionality/link/wan_link.o \
		                             $(PKG_BUILD_DIR)/src/functionality/speed/wan_speed.o \
									 $(PKG_BUILD_DIR)/src/ultils/file_handler.o \
		                             $(PKG_BUILD_DIR)/src/wan_monitor.o
endef

define Package/wan-monitor/install
	$(INSTALL_DIR) $(1)/usr/bin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/wan-monitor $(1)/usr/bin/
endef

$(eval $(call BuildPackage,wan-monitor))


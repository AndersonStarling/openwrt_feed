include $(TOPDIR)/rules.mk

PKG_NAME:=trace-kernel
PKG_VERSION:=1.0
PKG_RELEASE:=1

PKG_BUILD_DIR := $(BUILD_DIR)/$(PKG_NAME)

include $(INCLUDE_DIR)/package.mk

define Package/trace-kernel
  SECTION:=utils
  CATEGORY:=Utilities
  TITLE:=Trace kernel ultility
endef

define Package/trace-kernel/description
    Utility for tracing kernel functions.
endef

define Build/Compile

endef

define Package/trace-kernel/install
	echo "Install"
	$(INSTALL_DIR) $(1)/usr/bin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/trace_kernel_init.sh $(1)/usr/bin/
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/trace_kernel_deinit.sh $(1)/usr/bin/
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/trace_kernel_start.sh $(1)/usr/bin/
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/trace_kernel_stop.sh $(1)/usr/bin/
endef

$(eval $(call BuildPackage,trace-kernel))

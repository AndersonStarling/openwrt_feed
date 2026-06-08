include $(TOPDIR)/rules.mk

PKG_NAME:=app-monitor
PKG_VERSION:=1.0
PKG_RELEASE:=1

PKG_BUILD_DIR := $(BUILD_DIR)/$(PKG_NAME)

include $(INCLUDE_DIR)/package.mk

define Package/app-monitor
  SECTION:=utils
  CATEGORY:=Utilities
  TITLE:=App monitor
endef

define Package/app-monitor/description
    app monitor auto restart app when app crash
endef

define Build/Prepare
	mkdir -p $(PKG_BUILD_DIR)
	$(CP) ./src/* $(PKG_BUILD_DIR)/
endef

define Build/Compile
	$(TARGET_CC) $(TARGET_CFLAGS) -o $(PKG_BUILD_DIR)/app-monitor $(PKG_BUILD_DIR)/app_monitor.c
endef

define Package/app-monitor/install
	$(INSTALL_DIR) $(1)/usr/bin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/app-monitor $(1)/usr/bin/
endef

$(eval $(call BuildPackage,app-monitor))

include $(TOPDIR)/rules.mk

PKG_NAME:=hello-pkg
PKG_VERSION:=1.0
PKG_RELEASE:=1

PKG_BUILD_DIR := $(BUILD_DIR)/$(PKG_NAME)

include $(INCLUDE_DIR)/package.mk

define Package/hello-pkg
  SECTION:=utils
  CATEGORY:=Utilities
  TITLE:=Hello example
endef

define Package/hello-pkg/description
 Simple hello example.
endef

define Build/Prepare
	mkdir -p $(PKG_BUILD_DIR)
	$(CP) ./src/* $(PKG_BUILD_DIR)/
endef

define Build/Compile
	$(TARGET_CC) $(TARGET_CFLAGS) -o $(PKG_BUILD_DIR)/hello $(PKG_BUILD_DIR)/hello_pkg.c
endef

define Package/hello-pkg/install
	$(INSTALL_DIR) $(1)/usr/bin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/hello $(1)/usr/bin/
endef

$(eval $(call BuildPackage,hello-pkg))









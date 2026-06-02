include $(TOPDIR)/rules.mk

PKG_NAME:=hello-script
PKG_VERSION:=1.0
PKG_RELEASE:=1

PKG_BUILD_DIR := $(BUILD_DIR)/$(PKG_NAME)

include $(INCLUDE_DIR)/package.mk

define Package/hello-script
  SECTION:=utils
  CATEGORY:=Utilities
  TITLE:=Hello script example
endef

define Package/hello-script/description
    Simple hello script example.
endef

define Build/Compile

endef

define Package/hello-script/install
	echo "Install"
	$(INSTALL_DIR) $(1)/usr/bin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/hello_script.sh $(1)/usr/bin/
endef

$(eval $(call BuildPackage,hello-script))

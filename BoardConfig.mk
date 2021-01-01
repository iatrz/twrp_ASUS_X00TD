#
# Copyright (C) 2020 The Android Open Source Project
# Copyright (C) 2020 The TWRP Open Source Project
# Copyright (C) 2020 SebaUbuntu's TWRP device tree generator
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#

DEVICE_PATH := device/asus/ASUS_X00TD

# For building with minimal manifest
ALLOW_MISSING_DEPENDENCIES := true

# Architecture
TARGET_ARCH := arm64
TARGET_ARCH_VARIANT := armv8-a
TARGET_CPU_ABI := arm64-v8a
TARGET_CPU_ABI2 :=
TARGET_CPU_VARIANT := generic

TARGET_2ND_ARCH := arm
TARGET_2ND_ARCH_VARIANT := armv7-a-neon
TARGET_2ND_CPU_ABI := armeabi-v7a
TARGET_2ND_CPU_ABI2 := armeabi
TARGET_2ND_CPU_VARIANT := generic
TARGET_BOARD_SUFFIX := _64
TARGET_USES_64_BIT_BINDER := true

# Assert
TARGET_OTA_ASSERT_DEVICE := ASUS_X00TD

# File systems
BOARD_HAS_LARGE_FILESYSTEM := true
#BOARD_RECOVERYIMAGE_PARTITION_SIZE := 28856320 # This is the maximum known partition size, but it can be higher, so we just omit it
BOARD_SYSTEMIMAGE_PARTITION_TYPE := ext4
BOARD_USERDATAIMAGE_FILE_SYSTEM_TYPE := ext4
BOARD_VENDORIMAGE_FILE_SYSTEM_TYPE := ext4
TARGET_USERIMAGES_USE_EXT4 := true
TARGET_USERIMAGES_USE_F2FS := true
TARGET_COPY_OUT_VENDOR := vendor

# Kernel
BOARD_KERNEL_CMDLINE := earlycon=msm_serial_dm,0xc170000 androidboot.hardware=qcom ehci-hcd.park=3 lpm_levels.sleep_disabled=1 sched_enable_hmp=1 sched_enable_power_aware=1 service_locator.enable=1 swiotlb=1 androidboot.configfs=true androidboot.usbcontroller=a800000.dwc3 firmware_class.path=/vendor/firmware_mnt/image loop.max_part=7 androidboot.selinux=permissive buildvariant=eng printk.devkmsg=on
TARGET_PREBUILT_KERNEL := $(DEVICE_PATH)/prebuilt/Image.gz-dtb
BOARD_KERNEL_BASE := 0x00000000
BOARD_KERNEL_PAGESIZE := 4096
BOARD_RAMDISK_OFFSET := 0x01000000
BOARD_KERNEL_TAGS_OFFSET := 0x00000100
BOARD_FLASH_BLOCK_SIZE := 262144 # (BOARD_KERNEL_PAGESIZE * 64)
BOARD_MKBOOTIMG_ARGS += --ramdisk_offset $(BOARD_RAMDISK_OFFSET)
BOARD_MKBOOTIMG_ARGS += --tags_offset $(BOARD_KERNEL_TAGS_OFFSET)
BOARD_KERNEL_IMAGE_NAME := Image.gz-dtb
TARGET_KERNEL_ARCH := arm64
TARGET_KERNEL_HEADER_ARCH := arm64
TARGET_KERNEL_SOURCE := kernel/asus/ASUS_X00TD
TARGET_KERNEL_CONFIG := ASUS_X00TD_defconfig

# Ramdisk compression
LZMA_RAMDISK_TARGETS := recovery

# Platform
TARGET_BOARD_PLATFORM := sdm660

# Hack: prevent anti rollback
PLATFORM_SECURITY_PATCH := 2099-12-31
PLATFORM_VERSION := 16.1.0

# Crypto
TARGET_HW_DISK_ENCRYPTION := true
#TARGET_HW_DISK_ENCRYPT_NEW := true
TW_INCLUDE_CRYPTO := true
TARGET_CRYPTFS_HW_PATH := vendor/qcom/opensource/cryptfs_hw

# TWRP Configuration
TW_THEME := portrait_hdpi
TW_EXTRA_LANGUAGES := true
TW_SCREEN_BLANK_ON_BOOT := true
TW_INPUT_BLACKLIST := "hbtp_vm"
TW_USE_TOOLBOX := true
TW_THEME := portrait_hdpi
# MTP seems to cause a kernel panic, at least with some kernels, so disable it for now
TW_EXCLUDE_MTP := true
TWRP_INCLUDE_LOGCAT := true
TARGET_USES_LOGD := true
PLATFORM_SECURITY_PATCH := 2025-12-31
PLATFORM_VERSION := 9.0.0

# MultiROM configuration
MR_DEVICE_HOOKS := $(DEVICE_PATH)/multirom/mr_hooks.c
MR_DEVICE_HOOKS_VER := 6
MR_DEVICE_BOOTDEVICE := /dev/block/platform/soc/c0c4000.sdhci
MR_DPI := xhdpi
MR_DPI_FONT := 340
MR_ENCRYPTION := true
MR_ENCRYPTION_FAKE_PROPERTIES := true
MR_ENCRYPTION_FAKE_PROPERTIES_EXTRAS := $(DEVICE_PATH)/multirom/mr_fake_properties.c
MR_ENCRYPTION_SETUP_SCRIPT := $(DEVICE_PATH)/multirom/mr_cp_crypto.sh
MR_FSTAB := $(DEVICE_PATH)/recovery.fstab
MR_INIT_DEVICES := $(DEVICE_PATH)/multirom/mr_init_devices.c
MR_INPUT_TYPE := type_b
MR_KEXEC_MEM_MIN := 0x86000000
MR_NO_KEXEC := enabled
MR_PIXEL_FORMAT := "BGRA_8888"
MR_UNIFIED_TABS := true
MR_USE_MROM_FSTAB := true
MR_EXTRA_FIRMWARE_DIR := "/mrom_enc/vendor/firmware"
RECOVERY_GRAPHICS_USE_LINELENGTH := true
DEVICE_RESOLUTION := 1080x2160
TARGET_RECOVERY_IS_MULTIROM := true
MR_DEVICE_HAS_VENDOR_PARTITION := true
MR_DEVICE_HAS_DRM_GRAPHICS := true

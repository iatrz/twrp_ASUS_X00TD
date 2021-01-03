#include <stdlib.h>

// These are paths to folders in /sys which contain "uevent" file
// need to init this device.
// MultiROM needs to init framebuffer, mmc blocks, input devices,
// some ADB-related stuff and USB drives, if OTG is supported
// You can use * at the end to init this folder and all its subfolders
const char *mr_init_devices[] =
{
    // FrameBuffers
    //"/sys/class/graphics/fb0",
    "/sys/devices/virtual/graphics/fb0",
    //"/sys/class/graphics/fb1",
    "/sys/devices/virtual/graphics/fb1",

    // mmcblk
    "/sys/block/mmcblk0",
    "/sys/bus/mmc/drivers/mmcblk",

    // Storage devices
    "/sys/dev/block/*",
    "/sys/block/sda",
    "/sys/block/sdb",
    "/sys/block/sdc",
    "/sys/block/sdd",
    "/sys/block/sde",
    "/sys/block/sdf",

    // Internal storage
    "/sys/devices/soc/c0c4000.sdhci/mmc_host/mmc0/mmc0",
    "/sys/devices/soc/c0c4000.sdhci/mmc_host/mmc0/mmc0:0001/block/mmcblk0",
    "/sys/devices/soc/c0c4000.sdhci/mmc_host/mmc0/mmc0:0001",
    "/sys/devices/soc/c0c4000.sdhci/mmc_host/mmc0",
    "/sys/devices/soc/c0c4000.sdhci/leds/mmc0::",
    "/sys/module/mmcblk",

    
    /*"/sys/devices/soc/c0c4000.sdhci/host0/target0:0:0",
    "/sys/devices/soc/c0c4000.sdhci/host0/target0:0:0/0:0:0:0",
    "/sys/devices/soc/c0c4000.sdhci/host0/target0:0:0/0:0:0:1",
    "/sys/devices/soc/c0c4000.sdhci/host0/target0:0:0/0:0:0:2",
    "/sys/devices/soc/c0c4000.sdhci/host0/target0:0:0/0:0:0:3",
    "/sys/devices/soc/c0c4000.sdhci/host0/target0:0:0/0:0:0:4",
    "/sys/devices/soc/c0c4000.sdhci/host0/target0:0:0/0:0:0:5",
    "/sys/devices/soc/c0c4000.sdhci/host0/target0:0:0/0:0:0:0/block/sda",
    "/sys/devices/soc/c0c4000.sdhci/host0/target0:0:0/0:0:0:1/block/sdb",
    "/sys/devices/soc/c0c4000.sdhci/host0/target0:0:0/0:0:0:2/block/sdc",
    "/sys/devices/soc/c0c4000.sdhci/host0/target0:0:0/0:0:0:3/block/sdd",
    "/sys/devices/soc/c0c4000.sdhci/host0/target0:0:0/0:0:0:4/block/sde",
    "/sys/devices/soc/c0c4000.sdhci/host0/target0:0:0/0:0:0:5/block/sdf",
    "/sys/devices/soc/c0c4000.sdhci/host0/target0:0:0/0:0:0:0/block/sda/*",
    "/sys/devices/soc/c0c4000.sdhci/host0/target0:0:0/0:0:0:1/block/sdb/*",
    "/sys/devices/soc/c0c4000.sdhci/host0/target0:0:0/0:0:0:2/block/sdc/*",
    "/sys/devices/soc/c0c4000.sdhci/host0/target0:0:0/0:0:0:3/block/sdd/*",
    "/sys/devices/soc/c0c4000.sdhci/host0/target0:0:0/0:0:0:4/block/sde/*",
    "/sys/devices/soc/c0c4000.sdhci/host0/target0:0:0/0:0:0:5/block/sdf/*", */


    // External storage
    //"/sys/block/mmcblk1",
    //"/sys/block/mmcblk1",
    //"/sys/block/mmcblk1/mmcblk1p1",
    //"/sys/block/mmcblk1/mmcblk1p2",

    // Devices
    "/sys/bus*",
    "/sys/bus/mmc",
    "/sys/devices/virtual/mem/null",
    "/sys/devices/virtual/misc/fuse",

    // Inputs
    "/sys/class/input/event*",
    "/sys/class/input/input*",
    "/sys/class/misc/uinput",
    "/sys/module/uinput",
    "/sys/class/tty/ptmx",
    "/sys/devices/soc/soc:qcom,mdss_wb_panel",
    "/sys/devices/soc/soc:gpio_keys/input/input8",
    "/sys/devices/virtual/input*",
    "/sys/devices/virtual/misc/uinput",
    "/sys/devices/virtual/tty/ptmx",
    "/sys/devices/soc/a800000.ssusb/a904000.qcom,usbbam",
    "/sys/devices/soc/a800000.ssusb",
    "/sys/devices/soc/a800000.ssusb/a800000.dwc3*",

    "/sys/devices/soc/c176000.i2c/i2c-2/i2c-dev/i2c-2",
    "/sys/devices/soc/c176000.i2c/i2c-2",
    "/sys/devices/soc/c176000.i2c/i2c-2/2-0008",
    "/sys/devices/soc/c176000.i2c/i2c-2/2-0028",
    "/sys/devices/soc/c176000.i2c",
    "/sys/devices/soc/c178000.i2c/i2c-4/i2c-dev/i2c-4",
    "/sys/devices/soc/c178000.i2c/i2c-4",
    "/sys/devices/soc/c178000.i2c/i2c-4/4-0062",
    "/sys/devices/soc/c178000.i2c/i2c-4/4-0070",
    "/sys/devices/soc/c178000.i2c/i2c-4/4-0070/synaptics_dsxv27.0",
    "/sys/devices/soc/c178000.i2c",
    "/sys/devices/soc/c1b7000.i2c/i2c-7/i2c-dev/i2c-7",
    "/sys/devices/soc/c1b7000.i2c/i2c-7",
    "/sys/devices/soc/c1b7000.i2c/i2c-7/7-0048",
    "/sys/devices/soc/c1b7000.i2c",

    // ADB
    "/sys/devices/virtual/tty/ptmx",
    "/sys/bus/usb",
    "/sys/class/android_usb/android*",
    "/sys/class/misc/android_rndis_qc",
    "/sys/devices/virtual/misc/mtp_usb",

    // USB
    "/sys/bus/usb",
    "/sys/bus/platform/drivers/xhci-hcd*",
    "/sys/devices/soc/a800000.ssusb/a800000.dwc3/",

    // Encryption
    "/sys/devices/virtual/icesdcc/icesdcc",
    "/sys/devices/virtual/icesdcc/iceufs",
    "/sys/devices/virtual/misc/device-mapper",
    "/sys/devices/virtual/misc/ion",
    "/sys/devices/virtual/qseecom/qseecom",

    // Logging
    "/sys/devices/virtual/mem/kmsg",

    NULL
};

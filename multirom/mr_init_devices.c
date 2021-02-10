#include <stdlib.h>

// These are paths to folders in /sys which contain "uevent" file
// need to init this device.
// MultiROM needs to init framebuffer, mmc blocks, input devices,
// some ADB-related stuff and USB drives, if OTG is supported
// You can use * at the end to init this folder and all its subfolders
const char *mr_init_devices[] =
{
    // FrameBuffers
    "/sys/class/graphics/fb0",
    "/sys/bus/platform/drivers/*",
    "/sys/module/*",

    "/sys/block/mmcblk0/mmcblk0p*",
    

    // Internal storage
    /* "/sys/devices/soc/c0c4000.sdhci",
    "/sys/devices/soc/c0c4000.sdhci/host0/target0:0:0",
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
    
    /* "/sys/devices/soc/c084000.sdhci/mmc_host/mmc1/mmc1:0001/block/mmcblk1",
    "/sys/devices/soc/c084000.sdhci/mmc_host/mmc1/mmc1:0001",
    "/sys/devices/soc/c084000.sdhci/mmc_host/mmc1",
    "/sys/devices/soc/c0c4000.sdhci/mmc_host/mmc0/mmc0",
    "/sys/devices/soc/c0c4000.sdhci/mmc_host/mmc0/mmc0:0001/block/mmcblk0/mmcblk0p1",
    "/sys/devices/soc/c0c4000.sdhci/mmc_host/mmc0/mmc0:0001/block/mmcblk0/mmcblk0p2",
    "/sys/devices/soc/c0c4000.sdhci/mmc_host/mmc0/mmc0:0001/block/mmcblk0/mmcblk0p3",
    "/sys/devices/soc/c0c4000.sdhci/mmc_host/mmc0/mmc0:0001/block/mmcblk0/mmcblk0p4",
    "/sys/devices/soc/c0c4000.sdhci/mmc_host/mmc0/mmc0:0001/block/mmcblk0/mmcblk0p5",
    "/sys/devices/soc/c0c4000.sdhci/mmc_host/mmc0/mmc0:0001/block/mmcblk0/mmcblk0p6",
    "/sys/devices/soc/c0c4000.sdhci/mmc_host/mmc0/mmc0:0001/block/mmcblk0/mmcblk0p7",
    "/sys/devices/soc/c0c4000.sdhci/mmc_host/mmc0/mmc0:0001/block/mmcblk0/mmcblk0p8",
    "/sys/devices/soc/c0c4000.sdhci/mmc_host/mmc0/mmc0:0001/block/mmcblk0/mmcblk0p9",
    "/sys/devices/soc/c0c4000.sdhci/mmc_host/mmc0/mmc0:0001/block/mmcblk0/mmcblk0rpmb",
    "/sys/devices/soc/c0c4000.sdhci/mmc_host/mmc0/mmc0:0001/block/mmcblk0/mmcblk0p10",
    "/sys/devices/soc/c0c4000.sdhci/mmc_host/mmc0/mmc0:0001/block/mmcblk0/mmcblk0p11",
    "/sys/devices/soc/c0c4000.sdhci/mmc_host/mmc0/mmc0:0001/block/mmcblk0/mmcblk0p12",
    "/sys/devices/soc/c0c4000.sdhci/mmc_host/mmc0/mmc0:0001/block/mmcblk0/mmcblk0p13",
    "/sys/devices/soc/c0c4000.sdhci/mmc_host/mmc0/mmc0:0001/block/mmcblk0/mmcblk0p14",
    "/sys/devices/soc/c0c4000.sdhci/mmc_host/mmc0/mmc0:0001/block/mmcblk0/mmcblk0p15",
    "/sys/devices/soc/c0c4000.sdhci/mmc_host/mmc0/mmc0:0001/block/mmcblk0/mmcblk0p16",
    "/sys/devices/soc/c0c4000.sdhci/mmc_host/mmc0/mmc0:0001/block/mmcblk0/mmcblk0p17",
    "/sys/devices/soc/c0c4000.sdhci/mmc_host/mmc0/mmc0:0001/block/mmcblk0/mmcblk0p18",
    "/sys/devices/soc/c0c4000.sdhci/mmc_host/mmc0/mmc0:0001/block/mmcblk0/mmcblk0p19",
    "/sys/devices/soc/c0c4000.sdhci/mmc_host/mmc0/mmc0:0001/block/mmcblk0/mmcblk0p20",
    "/sys/devices/soc/c0c4000.sdhci/mmc_host/mmc0/mmc0:0001/block/mmcblk0/mmcblk0p21",
    "/sys/devices/soc/c0c4000.sdhci/mmc_host/mmc0/mmc0:0001/block/mmcblk0/mmcblk0p22",
    "/sys/devices/soc/c0c4000.sdhci/mmc_host/mmc0/mmc0:0001/block/mmcblk0/mmcblk0p23",
    "/sys/devices/soc/c0c4000.sdhci/mmc_host/mmc0/mmc0:0001/block/mmcblk0/mmcblk0p24",
    "/sys/devices/soc/c0c4000.sdhci/mmc_host/mmc0/mmc0:0001/block/mmcblk0/mmcblk0p25",
    "/sys/devices/soc/c0c4000.sdhci/mmc_host/mmc0/mmc0:0001/block/mmcblk0/mmcblk0p26",
    "/sys/devices/soc/c0c4000.sdhci/mmc_host/mmc0/mmc0:0001/block/mmcblk0/mmcblk0p27",
    "/sys/devices/soc/c0c4000.sdhci/mmc_host/mmc0/mmc0:0001/block/mmcblk0/mmcblk0p28",
    "/sys/devices/soc/c0c4000.sdhci/mmc_host/mmc0/mmc0:0001/block/mmcblk0/mmcblk0p29",
    "/sys/devices/soc/c0c4000.sdhci/mmc_host/mmc0/mmc0:0001/block/mmcblk0/mmcblk0p30",
    "/sys/devices/soc/c0c4000.sdhci/mmc_host/mmc0/mmc0:0001/block/mmcblk0/mmcblk0p31",
    "/sys/devices/soc/c0c4000.sdhci/mmc_host/mmc0/mmc0:0001/block/mmcblk0/mmcblk0p32",
    "/sys/devices/soc/c0c4000.sdhci/mmc_host/mmc0/mmc0:0001/block/mmcblk0/mmcblk0p33",
    "/sys/devices/soc/c0c4000.sdhci/mmc_host/mmc0/mmc0:0001/block/mmcblk0/mmcblk0p34",
    "/sys/devices/soc/c0c4000.sdhci/mmc_host/mmc0/mmc0:0001/block/mmcblk0/mmcblk0p35",
    "/sys/devices/soc/c0c4000.sdhci/mmc_host/mmc0/mmc0:0001/block/mmcblk0/mmcblk0p36",
    "/sys/devices/soc/c0c4000.sdhci/mmc_host/mmc0/mmc0:0001/block/mmcblk0/mmcblk0p37",
    "/sys/devices/soc/c0c4000.sdhci/mmc_host/mmc0/mmc0:0001/block/mmcblk0/mmcblk0p38",
    "/sys/devices/soc/c0c4000.sdhci/mmc_host/mmc0/mmc0:0001/block/mmcblk0/mmcblk0p39",
    "/sys/devices/soc/c0c4000.sdhci/mmc_host/mmc0/mmc0:0001/block/mmcblk0/mmcblk0p40",
    "/sys/devices/soc/c0c4000.sdhci/mmc_host/mmc0/mmc0:0001/block/mmcblk0/mmcblk0p41",
    "/sys/devices/soc/c0c4000.sdhci/mmc_host/mmc0/mmc0:0001/block/mmcblk0/mmcblk0p42",
    "/sys/devices/soc/c0c4000.sdhci/mmc_host/mmc0/mmc0:0001/block/mmcblk0/mmcblk0p43",
    "/sys/devices/soc/c0c4000.sdhci/mmc_host/mmc0/mmc0:0001/block/mmcblk0/mmcblk0p44",
    "/sys/devices/soc/c0c4000.sdhci/mmc_host/mmc0/mmc0:0001/block/mmcblk0/mmcblk0p45",
    "/sys/devices/soc/c0c4000.sdhci/mmc_host/mmc0/mmc0:0001/block/mmcblk0/mmcblk0p46",
    "/sys/devices/soc/c0c4000.sdhci/mmc_host/mmc0/mmc0:0001/block/mmcblk0/mmcblk0p47",
    "/sys/devices/soc/c0c4000.sdhci/mmc_host/mmc0/mmc0:0001/block/mmcblk0/mmcblk0p48",
    "/sys/devices/soc/c0c4000.sdhci/mmc_host/mmc0/mmc0:0001/block/mmcblk0/mmcblk0p49",
    "/sys/devices/soc/c0c4000.sdhci/mmc_host/mmc0/mmc0:0001/block/mmcblk0/mmcblk0p50",
    "/sys/devices/soc/c0c4000.sdhci/mmc_host/mmc0/mmc0:0001/block/mmcblk0/mmcblk0p51",
    "/sys/devices/soc/c0c4000.sdhci/mmc_host/mmc0/mmc0:0001/block/mmcblk0/mmcblk0p52",
    "/sys/devices/soc/c0c4000.sdhci/mmc_host/mmc0/mmc0:0001/block/mmcblk0/mmcblk0p53",
    "/sys/devices/soc/c0c4000.sdhci/mmc_host/mmc0/mmc0:0001/block/mmcblk0/mmcblk0p54",
    "/sys/devices/soc/c0c4000.sdhci/mmc_host/mmc0/mmc0:0001/block/mmcblk0/mmcblk0p55",
    "/sys/devices/soc/c0c4000.sdhci/mmc_host/mmc0/mmc0:0001/block/mmcblk0/mmcblk0p56",
    "/sys/devices/soc/c0c4000.sdhci/mmc_host/mmc0/mmc0:0001/block/mmcblk0/mmcblk0p57",
    "/sys/devices/soc/c0c4000.sdhci/mmc_host/mmc0/mmc0:0001/block/mmcblk0/mmcblk0p58",
    "/sys/devices/soc/c0c4000.sdhci/mmc_host/mmc0/mmc0:0001/block/mmcblk0/mmcblk0p59",
    "/sys/devices/soc/c0c4000.sdhci/mmc_host/mmc0/mmc0:0001/block/mmcblk0/mmcblk0p60",
    "/sys/devices/soc/c0c4000.sdhci/mmc_host/mmc0/mmc0:0001/block/mmcblk0/mmcblk0p61",
    "/sys/devices/soc/c0c4000.sdhci/mmc_host/mmc0/mmc0:0001/block/mmcblk0/mmcblk0p62",
    "/sys/devices/soc/c0c4000.sdhci/mmc_host/mmc0/mmc0:0001/block/mmcblk0/mmcblk0p63",
    "/sys/devices/soc/c0c4000.sdhci/mmc_host/mmc0/mmc0:0001/block/mmcblk0/mmcblk0p64",
    "/sys/devices/soc/c0c4000.sdhci/mmc_host/mmc0/mmc0:0001/block/mmcblk0/mmcblk0p65",
    "/sys/devices/soc/c0c4000.sdhci/mmc_host/mmc0/mmc0:0001/block/mmcblk0/mmcblk0p66",
    "/sys/devices/soc/c0c4000.sdhci/mmc_host/mmc0/mmc0:0001/block/mmcblk0",
    "/sys/devices/soc/c0c4000.sdhci/mmc_host/mmc0/mmc0:0001",
    "/sys/devices/soc/c0c4000.sdhci/mmc_host/mmc0",
    "/sys/devices/soc/soc:qcom,msm-pcm-hostless", */

    // External storage
    //"/sys/block/mmcblk1",
    //"/sys/block/mmcblk1",
    //"/sys/block/mmcblk1/mmcblk1p1",
    //"/sys/block/mmcblk1/mmcblk1p2",

    // Devices
    "/sys/bus*",
    "/sys/bus/mmc",
    "/sys/bus/mmc/drivers/mmcblk",
    "/sys/devices*",
    "/sys/module*",
    "/sys/devices/virtual/mem/null",
    "/sys/devices/virtual/misc/fuse",

    // Inputs
    "/sys/class/input/event*",
    "/sys/class/input/input*",
    "/sys/class/misc/uinput",
    "/sys/class/tty/ptmx",
    "/sys/devices/soc/soc:gpio_keys/input/input8",
    "/sys/devices/virtual/input*",
    "/sys/devices/virtual/misc/uinput",
    "/sys/devices/virtual/tty/ptmx",
    "/sys/devices/soc/c178000.i2c/i2c-4/4-0062",

    // ADB
    "/sys/devices/virtual/tty/ptmx",
    "/sys/bus/usb",
    "/sys/class/android_usb/android*",
    "/sys/class/misc/android_rndis_qc",
    "/sys/devices/virtual/misc/mtp_usb",

    // apparently: for qualcomm overlay - /dev/ion
    "/sys/devices/virtual/misc/ion",

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

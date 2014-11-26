echo 0x3 > /sys/class/cplddrv/cpld/spi_route_reg
echo 0x1 > /sys/class/cplddrv/cpld/ext_serial_if_route_reg
insmod psocmod.ko
insmod hotplug_psoc_spi_device.ko
mknod /dev/psoc1 c 64 0
mknod /dev/psoc2 c 64 1
mknod /dev/psoc3 c 64 2
mknod /dev/psoc4 c 64 3
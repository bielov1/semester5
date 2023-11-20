#!/bin/sh
#scripn is Used to access QEMU for ARM
#+++++++++++++++++++++++++++++++++++++

qemu-system-arm -kernel ~/repos/busybox/_install/boot/zImage -initrd /home/oda/repos/busybox/rootfs.cpio.gz -machine virt -nographic -m 512 -append "root=/dev/ram0 rw console=ttyAMA0,115200 mem=512M"

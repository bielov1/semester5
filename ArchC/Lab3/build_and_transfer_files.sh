#!/bin/sh
#Building new archive for QEMU
#+++++++++++++++++++++++++++++++++++++

#видаляємо файл hello.ko, якщо такий є
rm ~/repos/busybox/_install/hello.ko

#Компілюємо оновлений код hello.c щоб отримати hello.ko
make -C ~/repos/test2/

#Копіюємо hello.ko в busybox/_install
cp ~/repos/test2/hello.ko ~/repos/busybox/_install/hello.ko

#Перезбираємо архів rootfs
# Встановлення повного шляху до директорії
INSTALL_DIR="/home/oda/repos/busybox/_install/"

# Перехід у директорію
cd "$INSTALL_DIR" || exit

# Виконання команди
find . | cpio -o -H newc | gzip > ../rootfs.cpio.gz

echo 'Building is finished'


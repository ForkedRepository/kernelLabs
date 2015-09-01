# Kernel Compilation

## Configuration
        make help

        make xconfig

        make oldconfig

        make olddefconfig

## Compilation

        make -j4

## Installation
        make modules_install

        sudo cp arch/x86_64/boot/bzImage /boot/vmlinuz-4.1.6

        sudo cp .config /boot/config-4.1.6

        sudo cp System.map /boot/System.map.4.1.6

        sudo mkinitramfs -o /boot/initrd.img-4.1.6 4.1.6

## Modify Grub
* Look at /boot/grub/grub.cfg

        sudo update-grub

* disable splash option in grub
* Enable Linux boot Logo
        # more todo on that-> grub vga or gfxpayload ! May be change extravalue instead ?

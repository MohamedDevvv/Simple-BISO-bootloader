TARGET = ~/opt/cross/bin/i686-elf
CC = $(TARGET)-gcc
CFLAGS = -std=gnu99 -ffreestanding -O2 -Wall -Wextra

builds = ./build/kernel.o ./build/boot.o ./build/vga.o

clean:
	rm -rf build/* \
	rm ./*.iso \
	rm kernel

burn:
	sudo dd if=anotheros.iso of=/dev/sdb && sync

all: files.c link makeiso qemu

qemu:
	qemu-system-x86_64 anotherX86os.iso

makeiso:
	mkdir -p build/isodir/boot/grub
	cp grub.cfg build/isodir/boot/grub
	cp kernel build/isodir/boot/kernel
	@grub-mkrescue -o anotherX86os.iso build/isodir

link: $(builds)
	$(CC) -T linker.ld -o kernel \
	-ffreestanding -O2 -nostdlib $(builds) -lgcc

files.c:
	$(CC) -c boot.s -o ./build/boot.o
	$(CC) -c kernel.c -o ./build/kernel.o $(CFLAGS)
	$(CC) -c ./drivers/vga.c -o ./build/vga.o $(CFLAGS)
	# $(CC) -c ./libs/convert.h -o ./build/convert.o $(CFLAGS)



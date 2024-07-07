TARGET = i686-elf
CC = $(TARGET)-gcc
CFLAGS = -std=gnu99 -ffreestanding -O2 -Wall -Wextra

builds = ./build/kernel.o ./build/boot.o ./build/vga.o

burn:
	sudo dd if=anotheros.iso of=/dev/sdb && sync


git:
	git add drivers
	git add libs
	git add boot.s kernel.c linker.ld Makefile
	git commit -m "new update pushed from make file"
	git push

all: files.c link makeiso qemu

qemu:
	qemu-system-x86_64 anotheros.iso

makeiso:
	cp anotheros.bin isodir/boot/anotheros.bin
	@grub-mkrescue -o anotheros.iso isodir

link: $(builds)
	$(CC) -T linker.ld -o anotheros.bin -ffreestanding -O2 -nostdlib $(builds) -lgcc

files.c:
	$(CC) -c kernel.c -o ./build/kernel.o $(CFLAGS)
	$(CC) -c boot.s -o ./build/boot.o
	$(CC) -c ./drivers/vga.c -o ./build/vga.o $(CFLAGS)


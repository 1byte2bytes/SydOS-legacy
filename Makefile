assembly:
	nasm -f elf32 src/loader.s
	ld -T src/link.ld -melf_i386 src/loader.o -o kernel.elf

all:
	make assembly

.PHONY: iso all assembly

iso:
	make all
	cp kernel.elf iso/boot
	grub-mkrescue -o SydOS-dev.iso iso
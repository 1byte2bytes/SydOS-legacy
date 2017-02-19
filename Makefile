all:
	make c
	make assembly

assembly:
	nasm -f elf32 src/loader.s
	ld -T src/link.ld -melf_i386 src/loader.o -o kernel.elf

c:
	cd src/drivers/framebuffer && make

.PHONY: iso all assembly c

iso:
	make all
	cp kernel.elf iso/boot
	grub-mkrescue -o SydOS-dev.iso iso
all:
	rm -rf temp
	mkdir temp
	make c
	make assembly

assembly: 
	cd src/ && make
	cp src/loader.o temp/loader.o
	ld -T src/link.ld -melf_i386 temp/loader.o -o kernel.elf

c:
	cd src/drivers/framebuffer && make
	cp src/drivers/framebuffer/framebuffer.o temp/framebuffer.o

.PHONY: iso all assembly c

iso:
	make all
	cp kernel.elf iso/boot
	grub-mkrescue -o SydOS-dev.iso iso
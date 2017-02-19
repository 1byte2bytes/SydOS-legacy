all:
	rm -rf temp
	mkdir temp
	make c
	make assembly

assembly: 
	cd src/ && make
	cp src/*.o temp/
	ld -T src/link.ld -melf_i386 temp/loader.o $(shell find temp/ ! -name "loader.o" -name "*.o") -o kernel.elf

c:
	cd src/drivers/framebuffer && make
	cp src/drivers/framebuffer/framebuffer.o temp/framebuffer.o

.PHONY: iso all assembly c

iso:
	make all
	cp kernel.elf iso/boot
	grub-mkrescue -o SydOS-dev.iso iso
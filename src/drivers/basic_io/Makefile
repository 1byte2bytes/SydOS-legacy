ASMOBJ = outb.s inb.s
ASMSRCS = $(ASMOBJ:.s=.o)

all: $(ASMSRCS) driver
	
driver:
	rm -rf basic_io.o
	ld -r -melf_i386 *.o -o basic_io.o

%.o: %.s
	nasm -f elf32 $<
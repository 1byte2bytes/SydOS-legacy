ASMOBJ = outb.s
ASMSRCS = $(ASMOBJ:%.o=%.s)

all: compile driver
	
driver:
	rm -rf basic_io.o
	ld -r -melf_i386 *.o -o basic_io.o


compile: $(ASMSRCS)
	nasm -f elf32 $^
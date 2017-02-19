AFLAGS = -f elf32
ASMOBJ = loader.s
ASMSRCS = $(ASMOBJ:%.o=%.s)

all: clean compile_asm
	
clean:
	rm -rf *.o

compile_asm: $(ASMSRCS)
	nasm -f elf32 $^
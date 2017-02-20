AFLAGS = -f elf32
ASMOBJ = loader.s
ASMSRCS = $(ASMOBJ:%.o=%.s)

CFLAGS = -ggdb -m32 -nostdlib -nostdinc -fno-builtin -fno-stack-protector -nostartfiles -nodefaultlibs -Wall -Wextra -Werror -c
COBJ = main.c
CSRCS = $(COBJ:%.o=%.c)

all: clean compile_asm compile_c
	
clean:
	rm -rf *.o

compile_asm: $(ASMSRCS)
	nasm -f elf32 $^

compile_c: $(CSRCS)
	gcc $^ $(CFLAGS)
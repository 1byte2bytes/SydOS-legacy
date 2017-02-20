CFLAGS = -ggdb -m32 -nostdlib -nostdinc -fno-builtin -fno-stack-protector -nostartfiles -nodefaultlibs -Wall -Wextra -Werror -c
COBJ = fb_main.c
CSRCS = $(COBJ:%.o=%.c)

all: compile driver
	
driver:
	rm -rf framebuffer.o
	ld -r -melf_i386 *.o -o serial.o

compile: $(CSRCS)
	gcc $^ $(CFLAGS)
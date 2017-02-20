CFLAGS = -ggdb -m32 -nostdlib -nostdinc -fno-builtin -fno-stack-protector -nostartfiles -nodefaultlibs -Wall -Wextra -Werror -c
COBJ = serial_main.c
CSRCS = $(COBJ:%.o=%.c)

all: compile driver

driver:
	rm -rf serial.o
	ld -r -melf_i386 *.o -o serial.o

compile: $(CSRCS)
	gcc $^ $(CFLAGS)
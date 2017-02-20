DRIVERS = basic_io framebuffer

all: $(DRIVERS)

.PHONY: all $(DRIVERS)

basic_io:
	cd basic_io && make
	cp -v basic_io/basic_io.o ../../temp

framebuffer:
	cd framebuffer && make
	cp -v framebuffer/framebuffer.o ../../temp
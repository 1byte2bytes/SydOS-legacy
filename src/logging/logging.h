#include "../drivers/framebuffer/fb_main.h"
#include "../drivers/serial/serial_main.h"

void log_info(char* message) {
    serial_write(SERIAL_COM1_BASE, "[INFO   ] ");
    serial_write(SERIAL_COM1_BASE, message);
    serial_write(SERIAL_COM1_BASE, "\n");

    fb_write("[INFO   ] ");
    fb_write(message);
    fb_write("\n");
}

void log_warn(char* message) {
    serial_write(SERIAL_COM1_BASE, "[WARNING] ");
    serial_write(SERIAL_COM1_BASE, message);
    serial_write(SERIAL_COM1_BASE, "\n");

    fb_write("[WARNING] ");
    fb_write(message);
    fb_write("\n");
}

void log_fatal(char* message) {
    serial_write(SERIAL_COM1_BASE, "[FATAL  ] ");
    serial_write(SERIAL_COM1_BASE, message);
    serial_write(SERIAL_COM1_BASE, "\n");
    
    fb_write("[FATAL  ] ");
    fb_write(message);
    fb_write("\n");
}
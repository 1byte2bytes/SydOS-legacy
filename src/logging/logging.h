#include "../drivers/framebuffer/fb_main.h"

void log_info(char* message) {
    fb_write("[INFO   ] ");
    fb_write(message);
    fb_write("\n");
}

void log_warn(char* message) {
    fb_write("[WARNING] ");
    fb_write(message);
    fb_write("\n");
}

void log_fatal(char* message) {
    fb_write("[FATAL  ] ");
    fb_write(message);
    fb_write("\n");
}
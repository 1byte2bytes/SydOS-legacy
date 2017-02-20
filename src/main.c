#include "drivers/framebuffer/fb_main.h"

#if defined(__cplusplus)
extern "C" /* Use C linkage for kernel_main. */
#endif
void kern_main(void) {
    fb_write_char(0, 'S', 0, 15);
    fb_write("SydOS v0.0.1 PRERELEASE");
    while(1==1) {

    }
}
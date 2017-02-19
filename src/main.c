#include "drivers/framebuffer/fb_main.h"

#if defined(__cplusplus)
extern "C" /* Use C linkage for kernel_main. */
#endif
void kern_main(void) {
    fb_write(0, 'S', 0, 15);
    fb_write(2, 'y', 0, 15);
    fb_write(4, 'd', 0, 15);
    fb_write(6, 'O', 0, 15);
    fb_write(8, 'S', 0, 15);
    while(1==1) {

    }
}
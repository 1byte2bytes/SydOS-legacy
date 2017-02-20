#include "drivers/framebuffer/fb_main.h"
#include "logging/logging.h"

#if defined(__cplusplus)
extern "C" /* Use C linkage for kernel_main. */
#endif
void kern_main(void) {
    fb_write_char(0, 'S', 0, 15);
    log_info("Logging works!");
    log_warn("This is a warning");
    log_fatal("Looks like the kernel ran out of stuff to do!");
    while(1==1) {

    }
}
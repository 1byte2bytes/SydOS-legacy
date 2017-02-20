#include "drivers/framebuffer/fb_main.h"
#include "drivers/serial/serial_main.h"
#include "logging/logging.h"

#if defined(__cplusplus)
extern "C" /* Use C linkage for kernel_main. */
#endif
void kern_main(void) {
    fb_write_char(0, 'S', 0, 15);
    serial_configure_baud_rate(SERIAL_COM1_BASE, 3);
    log_info("Serial port configured");
    serial_configure_line(SERIAL_COM1_BASE);
    log_info("Serial line configured");
    serial_send_byte(SERIAL_COM1_BASE, 'h');
    log_info("Sent test data");
    serial_write(SERIAL_COM1_BASE, "Hello!");
    log_info("Sent test string");
    while(1==1) {

    }
}
#include "../basic_io/io.h"

#define SERIAL_COM1_BASE                0x3F8
#define SERIAL_DATA_PORT(base)          (base)
#define SERIAL_FIFO_COMMAND_PORT(base)  (base + 2)
#define SERIAL_LINE_COMMAND_PORT(base)  (base + 3)
#define SERIAL_MODEM_COMMAND_PORT(base) (base + 4)
#define SERIAL_LINE_STATUS_PORT(base)   (base + 5)

/** SERIAL_LINE_ENABLE_DLAB:
 *  Tells the serial port to expect the highest 8 bits first,
 *  then the lower 8 bits.
 */
#define SERIAL_LINE_ENABLE_DLAB         0x80

/** serial_configure_baud_rate:
 *  Sets the speed of the data communication. The default of a port is
 *  115200 bits/s. The argument is a divisor of that number.
 *
 *  @param The COM port to configure
 *  @param The divisor for the speed
 */
void serial_configure_baud_rate(unsigned short com, unsigned short divisor) {
    outb(SERIAL_LINE_COMMAND_PORT(com),
        SERIAL_LINE_ENABLE_DLAB);
    outb(SERIAL_DATA_PORT(com),
        (divisor >> 8) & 0x00FF);
    outb(SERIAL_DATA_PORT(com),
        divisor & 0x00FF);
}

/** serial_configure_line:
 *  Configures the line of the given serial port. The port will have
 *  a data length of 8 bits, no parity bits, one stop bit, and break
 *  control disabled.
 *
 *  @param The serial port to configure
 */
void serial_configure_line(unsigned short com) {
    outb(SERIAL_LINE_COMMAND_PORT(com), 0x03);
}

/** serial_is_transmit_fifo_empty:
 *  Checks wether the COM ports FIFO queue is empty
 *
 *  @param com The com port
 *  @return 0 if the FIFO queue is not empty
 *          1 if the FIFO queue is empty
 */
int serial_is_transmit_fifo_empty(unsigned int com) {
    return inb(SERIAL_LINE_STATUS_PORT(com)) & 0x20;
}
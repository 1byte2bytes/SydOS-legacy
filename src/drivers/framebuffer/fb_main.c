#include "../basic_io/io.h"

void fb_move_cursor(unsigned short pos);

char* fb_text_buffer = (char*)0x000B8000;

#define FB_COMMAND_PORT      0x3D4
#define FB_DATA_PORT         0x3D5
#define FB_HIGH_BYTE_COMMAND 14
#define FB_LOW_BYTE_COMMAND  15

int fb_console_width_total = 80;
int fb_console_height_total = 25;
int fb_console_x = 0;
int fb_console_y = 0;

int strlen(const char* str) {
    int len = 0;
    while(str[len]){
        len++;
    }
    return len;
}

/** fb_write:
 *  Writes a charecter to the screen at the specified location
 *
 *  @param i  The location in the framebuffer
 *  @param c  The charecter to write
 *  @param fg The foreground color in hex
 *  @param bg The background color in hex
 */
void fb_write_char(unsigned int i, char c, unsigned char fg, unsigned char bg) {
    fb_text_buffer[i] = c;
    fb_text_buffer[i + 1] = ((fg & 0x0F) << 4) | (bg & 0x0F);
}

void fb_write(const char* string) {
    int size = strlen(string);
    for (int i = 0; i < size; i++) {
        if(string[i] == '\n') {
            fb_console_y++;
            fb_console_x = 0;
        } else {
            int index = fb_console_y * fb_console_width_total + fb_console_x;
            fb_write_char(index*2, string[i], 0, 15);
            fb_console_x++;
        }
    }
    int index = fb_console_y * fb_console_width_total + fb_console_x;
    fb_move_cursor(index);
}

/** fb_move_cursor:
 *  Move the cursor to the position given to the function
 *
 *  @param pos The desired position for the cursor
 */
void fb_move_cursor(unsigned short pos) {
    outb(FB_COMMAND_PORT, FB_HIGH_BYTE_COMMAND);
    outb(FB_DATA_PORT,    ((pos >> 8) & 0x00FF));
    outb(FB_COMMAND_PORT, FB_LOW_BYTE_COMMAND);
    outb(FB_DATA_PORT,    pos & 0x00FF);
}
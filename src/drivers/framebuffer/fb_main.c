char* fb_text_buffer = (char*)0x000B8000;
int index = 0;

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
        fb_write_char(index, string[i], 0, 15);
    }
}
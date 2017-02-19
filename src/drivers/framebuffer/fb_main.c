char * fb_text_buffer = (char *)0x000B8000;

/** fb_write:
 *  Writes a charecter to the screen at the specified location
 *
 *  @param i  The location in the framebuffer
 *  @param c  The charecter to write
 *  @param fg The foreground color in hex
 *  @param bg The background color in hex
 */
void fb_write(unsigned int i, char c, unsigned char fg, unsigned char bg) {
    fb_text_buffer[i] = c;
    fb_text_buffer[i + 1] = ((fg & 0x0F) << 4) | (bg & 0x0F);
}
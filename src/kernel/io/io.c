#include "io.h"

unsigned short CURSOR_POSITION = 0;

void fb_write_cell(unsigned int i, char c, unsigned char fg, unsigned char bg){
	char* fb = (char*) 0x000B8000 + i;
	fb[i] = c;
	fb[i + 1] = ((fg & 0x0F) << 4 | (bg & 0x0F));
}

void fb_move_cursor(unsigned short pos){
	outb(IO_COMMAND_PORT, IO_HIGH_BYTE_COMMAND);
	outb(IO_DATA_PORT, ((pos >> 8) & 0x00FF));
	outb(IO_COMMAND_PORT, IO_LOW_BYTE_COMMAND);
	outb(IO_DATA_PORT, pos & 0x00FF);
}

void clearScreen(){
	for (int i = 0; i < 700; i++){
		writeChar(' ');
	}
	resetCursor();
}

void resetCursor(){
	CURSOR_POSITION = 0;
}

void writeChar(char data){
	fb_write_cell(CURSOR_POSITION++, data, IO_BLACK, IO_WHITE);
	// fb_move_cursor(CURSOR_POSITION++);
}

void writeHex(uint32_t hex){
	char chars[16] = "0123456789ABCDEF";
    unsigned char b = 0;
    int i;

    writeChar('0');
    writeChar('x');

    for (i = 7; i >= 0; --i) {
        b = (hex >> i*4) & 0x0F;
        writeChar(chars[b]);
    }
}

void write(char* buf, unsigned int len){
	for (int i = 0; i < (int) len; i++){
		writeChar(buf[i]);
	}
}
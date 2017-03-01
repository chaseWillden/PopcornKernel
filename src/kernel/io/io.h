#ifndef IO_H_
#define IO_H_

#include "../std/stdint.h"

#define IO_BLACK 0
#define IO_BLUE 1
#define IO_GREEN 2
#define IO_CYAN 3
#define IO_RED 4
#define IO_MAGENTA 5
#define IO_BROWN 6
#define IO_LIGHT_GREY 7
#define IO_DARK_GREY 8
#define IO_LIGHT_BLUE 9
#define IO_LIGHT_GREEN 10
#define IO_LIGHT_CYAN 11
#define IO_LIGHT_RED 12
#define IO_LIGHT_MAGENTA 13
#define IO_LIGHT_BROWN 15
#define IO_WHITE 15

// The I/O Ports
#define IO_COMMAND_PORT 0x3D4
#define IO_DATA_PORT 0x3D5

// The I/O Commands
#define IO_HIGH_BYTE_COMMAND 14
#define IO_LOW_BYTE_COMMAND 15

/**
 * Print a Cell 
 * @param Position
 * @param character
 * @param text color
 * @param background color
 */
void fb_write_cell(unsigned int i, char c, unsigned char fg, unsigned char bg);
void outb(unsigned short port, unsigned char data);
void fb_move_cursor(unsigned short pos);

// Driver
void resetCursor();
void clearScreen();
void writeChar(char data);
void write(char* buf, unsigned int len);
void writeHex(uint32_t hex);

#endif // IO_H_
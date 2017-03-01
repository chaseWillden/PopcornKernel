#ifndef GDT_H_
#define GDT_H_

#include "../std/stdint.h"

struct gdt {
	unsigned int address;
	unsigned short size;
} __attribute__((packed));

struct gdt load_gdt(struct gdt);

void InstallGDT();

#endif // GDT_H_
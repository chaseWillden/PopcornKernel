#include "kernel/io/io.h"
#include "kernel/gdt/gdt.h"
#include "kernel/mem/mem.h"
#include "kernel/std/stddef.h"

int main(kernel_meminfo_t* mem){
	InstallGDT();
	clearScreen();
	writeChar('W');
	writeChar('e');
	writeChar('l');
	writeChar('c');
	writeChar('o');
	writeChar('m');
	writeChar('e');

	if (mem != NULL){
		writeChar(' ');
		unsigned int vaddr = (unsigned int) mem->kernel_virtual_start;
		writeHex(vaddr);
	}

	unsigned int idt[512];
	idt[0] = 0xDEAD8E00;
	idt[1] = 0x0008BEEF;
}
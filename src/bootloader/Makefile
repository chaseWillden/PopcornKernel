all:
	nasm -f elf32 loader.s
	ld -T linker.ld -melf_i386 loader.o -o kernel.elf
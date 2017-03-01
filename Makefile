SRC = src
BOOTLOADER = $(SRC)/bootloader
KERNEL = $(SRC)/kernel
OBJECTS = $(addsuffix .o, $(basename $(shell find $(SRC) -type f \( -name '*.c' -or -name '*.s' \))))

CC = gcc
CFLAGS = -m32 -nostdlib -nostdinc -fno-builtin -fno-stack-protector \
         -nostartfiles -nodefaultlibs -Wall -Wextra -c
LDFLAGS = -T $(BOOTLOADER)/linker.ld -melf_i386
AS = nasm
ASFLAGS = -f elf

all: kernel.elf

setup:
	mkdir -p build

kernel.elf: $(OBJECTS)
	ld $(LDFLAGS) $(OBJECTS) -o kernel.elf
	make popcorn.iso
	make run

popcorn.iso: kernel.elf
	cp kernel.elf iso/boot/kernel.elf
	@genisoimage -R                              \
                    -b boot/grub/stage2_eltorito    \
                    -no-emul-boot                   \
                    -boot-load-size 4               \
                    -A popcorn                           \
                    -input-charset utf8             \
                    -quiet                          \
                    -boot-info-table                \
                    -o popcorn.iso                       \
                    iso

%.o: %.c
	$(CC) $(CFLAGS) $< -o $@

%.o: %.s
	$(AS) $(ASFLAGS) $< -o $@

run:
	VBoxManage startvm "Test"

clean:
	rm -rf kernel.elf popcorn.iso
	rm -rf iso/boot/kernel.elf
	find . -name '*.o' -type f -delete
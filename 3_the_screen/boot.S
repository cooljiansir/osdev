#define ASM_FILE
#include "include/multiboot.h"

.global start,main


.text

main:
start:
    jmp multiboot_entry
    .align 4

    .long MULTIBOOT_HEADER_MAGIC
    .long (MULTIBOOT_MEMORY_INFO | MULTIBOOT_PAGE_ALIGN)
    .long -(MULTIBOOT_HEADER_MAGIC + (MULTIBOOT_PAGE_ALIGN | MULTIBOOT_MEMORY_INFO))

multiboot_entry:
	pushl	%ebx
	cli
	call cmain
loop:
	jmp loop

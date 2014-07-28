#include "include/monitor.h"
#include "include/multiboot.h"
#include "include/descriptor.h"


int cmain(struct multiboot_info *boot_info){
	init_gdt();
	init_idt();
	int i = 0;
	int j;
	monitor_clear();
	printf("hello world changed!!\n");
    printf("test interrupt-----\n");
    asm volatile("sti\n\t":::);
    while(1);
    //asm volatile("sti\n\t"/*\
    		"movl $0xffffffff,%%eax\n\t"\
    //		"addl $0xfffff,%%eax\n\t"*/:::);
    //asm volatile("int $0x04");
    return 0;
}

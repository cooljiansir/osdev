#include "include/monitor.h"
#include "include/multiboot.h"
#include "include/descriptor.h"


int cmain(struct multiboot_info *boot_info){
	init_gdt();
	init_idt();
	int i = 0;
	int j;
	monitor_clear();
	printf("hello world!\n");
	for(;i<30;i++)
	{
		printf("%s:%d\n","This is line",i);
		for(j = 0;j<10000000;j++)
			;
	}
    printf("test interrupt-----\n");
    asm volatile("int $0x04");
    return 0;
}

#include "include/monitor.h"
#include "include/multiboot.h"
#include "include/descriptor.h"
#include "include/timer.h"

int cmain(struct multiboot_info *boot_info){
	init_gdt();
	init_idt();
	monitor_clear();
	printf("test timer:\n");
	init_timer(100);
	asm volatile("sti\n\t":::);
	return 0;
}

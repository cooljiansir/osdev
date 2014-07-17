#include "include/monitor.h"
#include "include/multiboot.h"


int cmain(struct multiboot_info *boot_info){
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
    return 0;
}

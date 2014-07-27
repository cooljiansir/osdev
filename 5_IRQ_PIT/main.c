#include "include/monitor.h"
#include "include/multiboot.h"
#include "include/descriptor.h"

/*
 * 测试结果：
 * 除0异常和int 0效果是一样的
 *  除0异常返回之后会继续执行该条指令（除0）所以会一直中断
*into溢出指令和int 4效果是一样的
 * 
 */


int cmain(struct multiboot_info *boot_info){
				init_gdt();
				init_idt();
				int i = 0;
				int j;
				monitor_clear();
				printf("hello world changed!!\n");
				printf("test div 0 interrupt-----\n");
				//i = 0;
				//j = 4/i;//div interrupt
				asm volatile("movl $0x7fffffff,%%eax\n\t"\
						"addl $0x7fffffff,%%eax\n\t"\
						"into\n\t":::"eax");
				while(1);
				return 0;
}

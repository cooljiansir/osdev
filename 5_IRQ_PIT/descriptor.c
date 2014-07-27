#include "include/descriptor.h"
#include "include/common.h"
#include "include/stack.h"

gdt_entry_t gdt_entries[5];
gdt_ptr_t	gdt_ptr;

idt_entry_t idt_entries[256];
idt_ptr_t	idt_ptr;

static void gdt_set_gate(gdt_entry_t *gdt,u32int base,u32int limit,u8int access,u8int gran)
{
	gdt->limit_low = (limit&0xFFFF);
	gdt->base_low = (base&0xFFFF);
	gdt->base_middle = ((base>>16)&0xFF);
	gdt->access = access;
	gdt->granularity = (limit>>16)&0x0F;
	gdt->granularity |= gran&0xF0;
	gdt->base_high = (base>>24)&0xFF;
}


static void gdt_flush()
{
	asm volatile(
		"lgdt (%%eax)\n\t"\
		"movw $0x10,%%ax\n\t"\
		"movw %%ax,%%ds\n\t"\
		"movw %%ax,%%es\n\t"\
		"movw %%ax,%%fs\n\t"\
		"movw %%ax,%%gs\n\t"\
		"movw %%ax,%%ss\n\t"\
		"movw $0x08,%%ax\n\t"\
		"ljmp $0x08,$1f\n\t"\
		"1:\n\t"\
		::"a"(&gdt_ptr):);
}


void init_gdt()
{
	gdt_set_gate(&gdt_entries[0],0,0,0,0);/*null segment*/
	gdt_set_gate(&gdt_entries[1],0,0xFFFFFFFF,0x9A,0xCF);/*sys code*/
	gdt_set_gate(&gdt_entries[2],0,0xFFFFFFFF,0x92,0xCF);/*sys data*/
	gdt_set_gate(&gdt_entries[3],0,0xFFFFFFFF,0x9A,0xCF);/*usr code*/
	gdt_set_gate(&gdt_entries[4],0,0xFFFFFFFF,0x92,0xCF);/*usr data*/

	gdt_ptr.base = (u32int)&gdt_entries;
	gdt_ptr.limit = (sizeof(gdt_entry_t)*5) - 1;

	gdt_flush();
}


static void idt_set_gate(idt_entry_t *idt,u32int base,u16int selector,u8int flags)
{
	idt->base_low = base&0xFFFF;
	idt->base_high = (base>>16)&0xFFFF;
	idt->selector = selector;
	idt->flags = flags;
	idt->always0 = 0;
}

static void idt_flush()
{
    asm volatile(
			"lidt (%%eax)\n\t"
			::"a"(&idt_ptr):);
}

void isr_handler(register_t reg)
{
        printf("Wow,interrupt comes!\n");
        printf("ds:%x\n",reg.ds);
        printf("edi:%x,esi:%x,ebp:%x,esp:%x,ebx:%x,edx:%x,ecx:%x,eax:%x\n",
        		reg.edi,reg.esi,reg.ebp,reg.esp,reg.ebx,reg.edx,reg.ecx,reg.eax);
        printf("int_no:%d,err_code:%d\n",reg.int_no,reg.err_code);
        /*printf("eip:%x,cs:%x,eflags:%x,useresp:%x,ss:%x\n",
        		reg.eip,reg.cs,reg.eflags,reg.useresp,reg.ss);*/
        printf("eip:%x,cs:%x,eflags:%x\n",
                		reg.eip,reg.cs,reg.eflags);
}
void irq_handler(){
	
}

void isr0();
void isr1();
void isr2();
void isr3();
void isr4();
void isr5();
void isr6();
void isr7();
void isr8();
void isr9();
void isr10();
void isr11();
void isr12();
void isr13();
void isr14();
void isr15();
void isr16();
void isr17();
void isr18();
void isr19();
void isr20();
void isr21();
void isr22();
void isr23();
void isr24();
void isr25();
void isr26();
void isr27();
void isr28();
void isr29();
void isr30();
void isr31();
void irq0();
void irq1();
void irq2();
void irq3();
void irq4();
void irq5();
void irq6();
void irq7();
void irq8();
void irq9();
void irq10();
void irq11();
void irq12();
void irq13();
void irq14();
void irq15();


void init_idt()
{
        int i;
        idt_ptr.limit = sizeof(idt_entries) - 1;
        idt_ptr.base = (u32int)&idt_entries;
        idt_set_gate(&idt_entries[0],(u32int)isr0,0x08,0x8E);
        idt_set_gate(&idt_entries[1],(u32int)isr1,0x08,0x8E);
        idt_set_gate(&idt_entries[2],(u32int)isr2,0x08,0x8E);
        idt_set_gate(&idt_entries[3],(u32int)isr3,0x08,0x8E);
        idt_set_gate(&idt_entries[4],(u32int)isr4,0x08,0x8E);
        idt_set_gate(&idt_entries[5],(u32int)isr5,0x08,0x8E);
        idt_set_gate(&idt_entries[6],(u32int)isr6,0x08,0x8E);
        idt_set_gate(&idt_entries[7],(u32int)isr7,0x08,0x8E);
        idt_set_gate(&idt_entries[8],(u32int)isr8,0x08,0x8E);
        idt_set_gate(&idt_entries[9],(u32int)isr8,0x08,0x8E);
        idt_set_gate(&idt_entries[10],(u32int)isr10,0x08,0x8E);
        idt_set_gate(&idt_entries[11],(u32int)isr11,0x08,0x8E);
        idt_set_gate(&idt_entries[12],(u32int)isr12,0x08,0x8E);
        idt_set_gate(&idt_entries[13],(u32int)isr13,0x08,0x8E);
        idt_set_gate(&idt_entries[14],(u32int)isr14,0x08,0x8E);
        idt_set_gate(&idt_entries[15],(u32int)isr15,0x08,0x8E);
        idt_set_gate(&idt_entries[16],(u32int)isr16,0x08,0x8E);
        idt_set_gate(&idt_entries[17],(u32int)isr17,0x08,0x8E);
        idt_set_gate(&idt_entries[18],(u32int)isr18,0x08,0x8E);
        idt_set_gate(&idt_entries[19],(u32int)isr19,0x08,0x8E);
        idt_set_gate(&idt_entries[20],(u32int)isr20,0x08,0x8E);
        idt_set_gate(&idt_entries[21],(u32int)isr21,0x08,0x8E);
        idt_set_gate(&idt_entries[22],(u32int)isr22,0x08,0x8E);
        idt_set_gate(&idt_entries[23],(u32int)isr23,0x08,0x8E);
        idt_set_gate(&idt_entries[24],(u32int)isr24,0x08,0x8E);
        idt_set_gate(&idt_entries[25],(u32int)isr25,0x08,0x8E);
        idt_set_gate(&idt_entries[26],(u32int)isr26,0x08,0x8E);
        idt_set_gate(&idt_entries[27],(u32int)isr27,0x08,0x8E);
        idt_set_gate(&idt_entries[28],(u32int)isr28,0x08,0x8E);
        idt_set_gate(&idt_entries[29],(u32int)isr29,0x08,0x8E);
        idt_set_gate(&idt_entries[30],(u32int)isr30,0x08,0x8E);
        idt_set_gate(&idt_entries[31],(u32int)isr31,0x08,0x8E);
        
        //set irq
        //remap the irq table
        //icw1
        outb(0x20,0x11);//master port
        outb(0xA0,0x11);//slave port
        //icw2
        outb(0x21,0x20);//master interrupt vector begins at 0x20
        outb(0xA1,0x28);//slave interrupt vector begins at 0x28
        //icw3
        outb(0x21,0x04);//slaves attatched to IR line 2
        outb(0xA1,0x02);//slave  in IR line 2 of master
        //icw4
        outb(0x21,0x01);
        outb(0xA1,0x01);
        			 
        
        idt_set_gate(&idt_entries[32],(u32int)irq0,0x08,0x8E);
        idt_set_gate(&idt_entries[33],(u32int)irq1,0x08,0x8E);
        idt_set_gate(&idt_entries[34],(u32int)irq2,0x08,0x8E);
        idt_set_gate(&idt_entries[35],(u32int)irq3,0x08,0x8E);
        idt_set_gate(&idt_entries[36],(u32int)irq4,0x08,0x8E);
        idt_set_gate(&idt_entries[37],(u32int)irq5,0x08,0x8E);
        idt_set_gate(&idt_entries[38],(u32int)irq6,0x08,0x8E);
        idt_set_gate(&idt_entries[39],(u32int)irq7,0x08,0x8E);
        idt_set_gate(&idt_entries[40],(u32int)irq8,0x08,0x8E);
        idt_set_gate(&idt_entries[41],(u32int)irq9,0x08,0x8E);
        idt_set_gate(&idt_entries[42],(u32int)irq10,0x08,0x8E);
        idt_set_gate(&idt_entries[43],(u32int)irq11,0x08,0x8E);
        idt_set_gate(&idt_entries[44],(u32int)irq12,0x08,0x8E);
        idt_set_gate(&idt_entries[45],(u32int)irq13,0x08,0x8E);
        idt_set_gate(&idt_entries[46],(u32int)irq14,0x08,0x8E);
        idt_set_gate(&idt_entries[47],(u32int)irq15,0x08,0x8E);
        
        idt_flush();
}


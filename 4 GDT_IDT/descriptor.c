#include "include/descriptor.h"
#include "include/common.h"

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

void isr_handler()
{
        printf("Wow,interrupt comes!\n");
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
		idt_flush();
}


/*
 *It's too boring to write 256 functions
 *(They are almost the same!)
 *So use assembly macro
 *
 *Here,I don't know how to write asm macro in c
 *I tried code,but failed:(
 * 
 *
 */
/*asm (
        ".macro ISR_NOERRCODE arg1\n\t"\
        ".global isr\\arg1\n\t"\
        "isr\\arg1:\n\t"\
        "cli\n\t"\
        "pushb %0\n\t"\
        "pushb \\arg1\n\t"\
        "jmp isr_common_stub\n\t"\
        ".endm\n\t");
asm (
        ".macro ISR_ERRCODE arg1\n\t"\
        ".global isr\\arg1\n\t"\
        "isr\\arg1:\n\t"\
        "cli\n\t"\
        "pushb \\arg1\n\t"\
        "jmp isr_common_stub\n\t"\
        ".endm\n\t"
        );
asm(
        "isr_common_stub:\n\t"\
        "pusha\n\t"\
        "movw %%ds,%%ax\n\t"\
        "pushl %%eax\n\t"\
        "movw $0x10,%%ax\n\t"\
        "movw %%ax,%%ds\n\t"\
        "movw %%ax,%%es\n\t"\
        "movw %%ax,%%fs\n\t"\
        "movw %%ax,%%gs\n\t"\
        "call isr_handler\n\t"\
        "popl eax\n\t"\
        "movw %%ax,%%ds\n\t"\
        "movw %%ax,%%es\n\t"\
        "movw %%ax,%%fs\n\t"\
        "movw %%ax,%%gs\n\t"\
        "popa\n\t"\
        "addl %%esp,$8\n\t"\
        "sti\n\t"\
        "iret\n\t"
);*/



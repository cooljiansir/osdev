#ifndef _DESCRIPTOR_H_
#define _DESCRIPTOR_H_

#include "common.h"
#include "stack.h"


struct gdt_struct
{
	u16int	limit_low;
	u16int 	base_low;
	u8int	base_middle;
	u8int 	access;
	u8int 	granularity;
	u8int	base_high;
} __attribute__((packed));

typedef struct gdt_struct gdt_entry_t;

struct gdt_ptr_struct
{
	u16int 	limit;
	u32int	base;
} __attribute__((packed)); 

typedef struct gdt_ptr_struct gdt_ptr_t;

//initial gdt

void init_gdt();

struct idt_entry_struct
{
    u16int base_low;
    u16int selector;
    u8int always0;
    u8int flags;
    u16int base_high;
} __attribute__((packed));

typedef struct idt_entry_struct idt_entry_t;

struct idt_ptr_struct
{
    u16int limit;
    u32int base;
} __attribute__((packed));

typedef struct idt_ptr_struct idt_ptr_t;

void init_idt();

typedef void (*isr_t)(register_t);
void register_int_handler(u8int n,isr_t hanlder);

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
void isr32();
void isr33();
void isr34();
void isr35();
void isr36();
void isr37();
void isr38();
void isr39();
void isr40();
void isr41();
void isr42();
void isr43();
void isr44();
void isr45();
void isr46();
void isr47();
#endif

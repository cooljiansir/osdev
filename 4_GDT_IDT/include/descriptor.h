#ifndef _DESCRIPTOR_H_
#define _DESCRIPTOR_H_

#include "common.h"



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


#endif

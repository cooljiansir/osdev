.macro ISR_NOERRCODE arg1
.global isr\arg1

isr\arg1:
        cli
        push $0	
        push $\arg1
        jmp isr_common_stub
.endm

.macro ISR_ERRCODE arg1
.global isr\arg1
isr\arg1:
        cli
        push \arg1
        jmp isr_common_stub
.endm


.section .text
/************0-31 System preseved****************/
        ISR_NOERRCODE 0
        ISR_NOERRCODE 1
        ISR_NOERRCODE 2
        ISR_NOERRCODE 3
        ISR_NOERRCODE 4
        ISR_NOERRCODE 5
        ISR_NOERRCODE 6
        ISR_NOERRCODE 7
        ISR_NOERRCODE 8
        ISR_NOERRCODE 9
        ISR_NOERRCODE 10
        ISR_NOERRCODE 11
        ISR_NOERRCODE 12
        ISR_NOERRCODE 13
        ISR_NOERRCODE 14
        ISR_NOERRCODE 15
        ISR_NOERRCODE 16
        ISR_NOERRCODE 17
        ISR_NOERRCODE 18
        ISR_NOERRCODE 19
        ISR_NOERRCODE 20
        ISR_NOERRCODE 21
        ISR_NOERRCODE 22
        ISR_NOERRCODE 23
        ISR_NOERRCODE 24
        ISR_NOERRCODE 25
        ISR_NOERRCODE 26
        ISR_NOERRCODE 27
        ISR_NOERRCODE 28
        ISR_NOERRCODE 29
        ISR_NOERRCODE 30
        ISR_NOERRCODE 31
        
/************32-47 Outside interrupt****************/
	ISR_NOERRCODE 32
	ISR_NOERRCODE 33
	ISR_NOERRCODE 34
	ISR_NOERRCODE 35
	ISR_NOERRCODE 36
	ISR_NOERRCODE 37
	ISR_NOERRCODE 38
	ISR_NOERRCODE 39
	ISR_NOERRCODE 40
	ISR_NOERRCODE 41
	ISR_NOERRCODE 42
	ISR_NOERRCODE 43
	ISR_NOERRCODE 44
	ISR_NOERRCODE 45
	ISR_NOERRCODE 46
	ISR_NOERRCODE 47
		  

isr_common_stub:
        pusha
        xor %eax,%eax
        movw %ds,%ax
        pushl %eax

        movw $0x10,%ax
        movw %ax,%ds
        movw %ax,%es
        movw %ax,%fs
        movw %ax,%gs

        call isr_handler

	xor %eax,%eax
        popl %eax
        movw %ax,%ds
        movw %ax,%es
        movw %ax,%fs
        movw %ax,%gs

        popa

        addl $8,%esp

        sti
        iret

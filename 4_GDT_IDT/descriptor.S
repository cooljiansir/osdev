.macro ISR_NOERRCODE arg1
.global isr\arg1

isr\arg1:
        cli
        push $0				/*pushb=push? pushb will cause compile error*/
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
.global isr_common_stub

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


isr_common_stub:
        pusha
        movw %ds,%ax
        pushl %eax

        movw $0x10,%ax
        movw %ax,%ds
        movw %ax,%es
        movw %ax,%fs
        movw %ax,%gs

        call isr_handler

        popl %eax
        movw %ax,%ds
        movw %ax,%es
        movw %ax,%fs
        movw %ax,%gs

        popa

        addl $8,%esp

        sti
        iret

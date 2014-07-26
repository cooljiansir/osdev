	.file	"descriptor.c"
	.comm	gdt_entries,40,32
	.comm	gdt_ptr,6,1
	.comm	idt_entries,2048,32
	.comm	idt_ptr,6,1
	.text
	.type	gdt_set_gate, @function
gdt_set_gate:
.LFB0:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$8, %esp
	movl	20(%ebp), %edx
	movl	24(%ebp), %eax
	movb	%dl, -4(%ebp)
	movb	%al, -8(%ebp)
	movl	16(%ebp), %eax
	movl	%eax, %edx
	movl	8(%ebp), %eax
	movw	%dx, (%eax)
	movl	12(%ebp), %eax
	movl	%eax, %edx
	movl	8(%ebp), %eax
	movw	%dx, 2(%eax)
	movl	12(%ebp), %eax
	shrl	$16, %eax
	movl	%eax, %edx
	movl	8(%ebp), %eax
	movb	%dl, 4(%eax)
	movl	8(%ebp), %eax
	movzbl	-4(%ebp), %edx
	movb	%dl, 5(%eax)
	movl	16(%ebp), %eax
	shrl	$16, %eax
	movl	%eax, %edx
	andl	$15, %edx
	movl	8(%ebp), %eax
	movb	%dl, 6(%eax)
	movl	8(%ebp), %eax
	movzbl	6(%eax), %eax
	movzbl	-8(%ebp), %edx
	andl	$-16, %edx
	orl	%edx, %eax
	movl	%eax, %edx
	movl	8(%ebp), %eax
	movb	%dl, 6(%eax)
	movl	12(%ebp), %eax
	shrl	$24, %eax
	movl	%eax, %edx
	movl	8(%ebp), %eax
	movb	%dl, 7(%eax)
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE0:
	.size	gdt_set_gate, .-gdt_set_gate
	.type	gdt_flush, @function
gdt_flush:
.LFB1:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	$gdt_ptr, %eax
#APP
# 24 "descriptor.c" 1
	lgdt (%eax)
	movw $0x10,%ax
	movw %ax,%ds
	movw %ax,%es
	movw %ax,%fs
	movw %ax,%gs
	movw %ax,%ss
	movw $0x08,%ax
	ljmp $0x08,$1f
	1:
	
# 0 "" 2
#NO_APP
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE1:
	.size	gdt_flush, .-gdt_flush
	.globl	init_gdt
	.type	init_gdt, @function
init_gdt:
.LFB2:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$20, %esp
	movl	$0, 16(%esp)
	movl	$0, 12(%esp)
	movl	$0, 8(%esp)
	movl	$0, 4(%esp)
	movl	$gdt_entries, (%esp)
	call	gdt_set_gate
	movl	$207, 16(%esp)
	movl	$154, 12(%esp)
	movl	$-1, 8(%esp)
	movl	$0, 4(%esp)
	movl	$gdt_entries+8, (%esp)
	call	gdt_set_gate
	movl	$207, 16(%esp)
	movl	$146, 12(%esp)
	movl	$-1, 8(%esp)
	movl	$0, 4(%esp)
	movl	$gdt_entries+16, (%esp)
	call	gdt_set_gate
	movl	$207, 16(%esp)
	movl	$154, 12(%esp)
	movl	$-1, 8(%esp)
	movl	$0, 4(%esp)
	movl	$gdt_entries+24, (%esp)
	call	gdt_set_gate
	movl	$207, 16(%esp)
	movl	$146, 12(%esp)
	movl	$-1, 8(%esp)
	movl	$0, 4(%esp)
	movl	$gdt_entries+32, (%esp)
	call	gdt_set_gate
	movl	$gdt_entries, %eax
	movl	%eax, gdt_ptr+2
	movw	$39, gdt_ptr
	call	gdt_flush
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE2:
	.size	init_gdt, .-init_gdt
	.type	idt_set_gate, @function
idt_set_gate:
.LFB3:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$8, %esp
	movl	16(%ebp), %edx
	movl	20(%ebp), %eax
	movw	%dx, -4(%ebp)
	movb	%al, -8(%ebp)
	movl	12(%ebp), %eax
	movl	%eax, %edx
	movl	8(%ebp), %eax
	movw	%dx, (%eax)
	movl	12(%ebp), %eax
	shrl	$16, %eax
	movl	%eax, %edx
	movl	8(%ebp), %eax
	movw	%dx, 6(%eax)
	movl	8(%ebp), %eax
	movzwl	-4(%ebp), %edx
	movw	%dx, 2(%eax)
	movl	8(%ebp), %eax
	movzbl	-8(%ebp), %edx
	movb	%dl, 5(%eax)
	movl	8(%ebp), %eax
	movb	$0, 4(%eax)
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE3:
	.size	idt_set_gate, .-idt_set_gate
	.type	idt_flush, @function
idt_flush:
.LFB4:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	$idt_ptr, %eax
#APP
# 65 "descriptor.c" 1
	lidt (%eax)
	
# 0 "" 2
#NO_APP
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE4:
	.size	idt_flush, .-idt_flush
#APP
	.macro ISR_NOERRCODE arg1
	.global isr\arg1
	isr\arg1:
	cli
	pushb %0
	pushb \arg1
	jmp isr_common_stub
	.endm
	
	.macro ISR_ERRCODE arg1
	.global isr\arg1
	isr\arg1:
	cli
	pushb \arg1
	jmp isr_common_stub
	.endm
	movw %%ds,%%ax
	isr_common_stub:
	pusha
	
	.section	.rodata
.LC0:
	.string	"Wow,interrupt comes!"
#NO_APP
	.text
	.globl	isr_handler
	.type	isr_handler, @function
isr_handler:
.LFB5:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	$.LC0, (%esp)
	call	puts
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE5:
	.size	isr_handler, .-isr_handler
	.ident	"GCC: (Ubuntu/Linaro 4.7.2-2ubuntu1) 4.7.2"
	.section	.note.GNU-stack,"",@progbits

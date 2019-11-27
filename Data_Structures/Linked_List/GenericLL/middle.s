	.file	"middle.c"
	.text
	.globl	appendt
	.type	appendt, @function
appendt:
.LFB38:
	.cfi_startproc
	pushq	%r12
	.cfi_def_cfa_offset 16
	.cfi_offset 12, -16
	pushq	%rbp
	.cfi_def_cfa_offset 24
	.cfi_offset 6, -24
	pushq	%rbx
	.cfi_def_cfa_offset 32
	.cfi_offset 3, -32
	movq	%rdi, %rbp
	movq	%rsi, %r12
	movl	$16, %edi
	call	malloc
	movq	%rax, %rbx
	movl	$8, %edi
	call	malloc
	movq	%rax, (%rbx)
	movsd	(%r12), %xmm0
	movsd	%xmm0, (%rax)
	movq	$0, 8(%rbx)
	movq	0(%rbp), %rdx
	testq	%rdx, %rdx
	jne	.L2
	movq	%rbx, 0(%rbp)
	jmp	.L1
.L4:
	movq	%rax, %rdx
.L2:
	movq	8(%rdx), %rax
	testq	%rax, %rax
	jne	.L4
	movq	%rbx, 8(%rdx)
.L1:
	popq	%rbx
	.cfi_def_cfa_offset 24
	popq	%rbp
	.cfi_def_cfa_offset 16
	popq	%r12
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE38:
	.size	appendt, .-appendt
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC0:
	.string	"The linked list is empty "
.LC1:
	.string	"%lf \n"
	.section	.rodata.str1.8,"aMS",@progbits,1
	.align 8
.LC2:
	.string	"The total number of elements in the Linked List are: %d \n"
	.text
	.globl	printList
	.type	printList, @function
printList:
.LFB39:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushq	%rbx
	.cfi_def_cfa_offset 24
	.cfi_offset 3, -24
	subq	$8, %rsp
	.cfi_def_cfa_offset 32
	movq	%rdi, %rbx
	testq	%rdi, %rdi
	jne	.L7
	movl	$.LC0, %edi
	call	puts
.L7:
	movl	$0, %ebp
	jmp	.L8
.L9:
	addl	$1, %ebp
	movq	(%rbx), %rax
	movsd	(%rax), %xmm0
	movl	$.LC1, %esi
	movl	$1, %edi
	movl	$1, %eax
	call	__printf_chk
	movq	8(%rbx), %rbx
.L8:
	testq	%rbx, %rbx
	jne	.L9
	movl	%ebp, %edx
	movl	$.LC2, %esi
	movl	$1, %edi
	movl	$0, %eax
	call	__printf_chk
	addq	$8, %rsp
	.cfi_def_cfa_offset 24
	popq	%rbx
	.cfi_def_cfa_offset 16
	popq	%rbp
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE39:
	.size	printList, .-printList
	.section	.rodata.str1.1
.LC3:
	.string	"The List is empty "
	.text
	.globl	getmiddle
	.type	getmiddle, @function
getmiddle:
.LFB40:
	.cfi_startproc
	testq	%rdi, %rdi
	jne	.L12
	subq	$8, %rsp
	.cfi_def_cfa_offset 16
	movl	$.LC3, %edi
	call	puts
	movl	$0, %eax
	jmp	.L13
.L12:
	.cfi_def_cfa_offset 8
	cmpq	$0, 8(%rdi)
	jne	.L17
	movq	(%rdi), %rax
	cvttsd2si	(%rax), %eax
	ret
.L16:
	movq	8(%rax), %rdi
	movq	8(%rdx), %rdx
	jmp	.L14
.L17:
	movq	%rdi, %rdx
.L14:
	testq	%rdi, %rdi
	je	.L15
	movq	8(%rdi), %rax
	testq	%rax, %rax
	jne	.L16
.L15:
	movq	(%rdx), %rax
	cvttsd2si	(%rax), %eax
	ret
.L13:
	.cfi_def_cfa_offset 16
	addq	$8, %rsp
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE40:
	.size	getmiddle, .-getmiddle
	.section	.rodata.str1.1
.LC4:
	.string	"Input a number: "
.LC5:
	.string	"%d"
	.section	.rodata.str1.8
	.align 8
.LC6:
	.string	"Input array to be inserted into Linked List: "
	.section	.rodata.str1.1
.LC7:
	.string	"%lf"
.LC8:
	.string	"The middle element is: %d \n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB41:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%r12
	pushq	%rbx
	subq	$32, %rsp
	.cfi_offset 12, -24
	.cfi_offset 3, -32
	movq	%fs:40, %rax
	movq	%rax, -24(%rbp)
	xorl	%eax, %eax
	movq	$0, -32(%rbp)
	movl	$.LC4, %edi
	call	puts
	leaq	-36(%rbp), %rsi
	movl	$.LC5, %edi
	movl	$0, %eax
	call	__isoc99_scanf
	movslq	-36(%rbp), %rax
	leaq	22(,%rax,8), %rax
	andq	$-16, %rax
	subq	%rax, %rsp
	movq	%rsp, %r12
	movl	$.LC6, %edi
	call	puts
	movl	$0, %ebx
	jmp	.L21
.L22:
	movslq	%ebx, %rax
	leaq	(%r12,%rax,8), %rsi
	movl	$.LC7, %edi
	movl	$0, %eax
	call	__isoc99_scanf
	addl	$1, %ebx
.L21:
	cmpl	-36(%rbp), %ebx
	jl	.L22
	movl	$0, %ebx
	jmp	.L23
.L24:
	movslq	%ebx, %rax
	leaq	(%r12,%rax,8), %rsi
	leaq	-32(%rbp), %rdi
	call	appendt
	addl	$1, %ebx
.L23:
	cmpl	-36(%rbp), %ebx
	jl	.L24
	movq	-32(%rbp), %rdi
	call	printList
	movq	-32(%rbp), %rdi
	call	getmiddle
	movl	%eax, %edx
	movl	$.LC8, %esi
	movl	$1, %edi
	movl	$0, %eax
	call	__printf_chk
	movl	$0, %eax
	movq	-24(%rbp), %rcx
	xorq	%fs:40, %rcx
	je	.L25
	call	__stack_chk_fail
.L25:
	leaq	-16(%rbp), %rsp
	popq	%rbx
	popq	%r12
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE41:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.12) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits

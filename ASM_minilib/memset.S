.global memset

memset:
	push	%ebp
	mov	%esp, %ebp
	push	%ebx
	push	%ecx
	push	%edx
	mov	8(%ebp), %edx
	mov	12(%ebp), %ebx
	mov	16(%ebp), %ecx
	cmp	$0, %ecx
	JZ	d
b:	movb	%bl, (%edx)
	inc	%edx
	loop	b
d:	mov	8(%ebp), %eax
	pop	%edx
	pop	%ecx
	pop	%ebx
	leave
	ret

.global memmove

memmove:
	push	%ebp
	mov	%esp, %ebp
	push	%ebx
	push	%ecx
	push	%edx
	mov	12(%ebp), %ebx
	mov	16(%ebp), %ecx
	cmp	$0, %ecx
	JZ	d
b:	push	(%ebx)
	inc	%ebx
	loop	b
	mov	16(%ebp), %ecx
	mov	8(%ebp), %edx
	cmp	$0, %ecx
	JZ	d
	add	%ecx, %edx
c:	dec	%edx
	pop	%ebx
	movb	%bl, (%edx)
	loop	c
d:	mov	8(%ebp), %eax
	pop	%edx
	pop	%ecx
	pop	%ebx
	leave
	ret

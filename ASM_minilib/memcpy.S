.global memcpy

/*
 memcpy
 memcpy(void *dst, const void *src, size_t len)
 copies len bytes from string src to string dst
 returns the original value of dst
*/

memcpy:
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
b:	mov	(%ebx), %eax
	movb	%al, (%edx)
	inc	%ebx
	inc	%edx
	loop	b
d:	mov	8(%ebp), %eax
	pop	%edx
	pop	%ecx
	pop	%ebx
	leave
	ret

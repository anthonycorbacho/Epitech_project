.global write

/*
 ssize_t
 write(int d, const void *buf, size_t nbytes) ;
*/

write:
	push	%ebp
	mov	%esp, %ebp
	push	%ebx
	push	%ecx
	push	%edx
	mov	8(%ebp), %ebx
	mov	12(%ebp), %ecx
	mov	16(%ebp), %edx
	mov	$4, %eax
	push	%edx
	push	%ecx
	push	%ebx
	push	%eax
	int	$0x80
	add	$16, %esp
	pop	%edx
	pop	%ecx
	pop	%ebx
	leave
	ret

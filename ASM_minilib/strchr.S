.global strchr

/*
 Strchr (char *s, int c)
 returns the address of the first occurence of c in s
 returns null if not found
*/	
strchr:
	push	%ebp
	mov	%esp, %ebp
	push	%ebx
	push	%ecx
	push	%edx
	mov	8(%ebp), %ebx
	mov	12(%ebp), %ecx
	dec	%ebx
t:	inc	%ebx
	cmpb	%cl, (%ebx)
	JZ	found
	cmpb	$0, (%ebx)
	JNZ	t
	mov	$0, %ebx
found:	mov	%ebx, %eax
	pop	%edx
	pop	%ecx
	pop	%ebx
	leave
	ret

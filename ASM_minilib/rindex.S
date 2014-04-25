.global rindex

/*
 char *rindex(const char *s, int c)
 returns the address of the last occurence of c in s
 returns null if not found
*/
rindex:
	push	%ebp
	mov	%esp, %ebp
	push	%ebx
	push	%ecx
	push	%edx
	mov	8(%ebp), %ebx
	mov	12(%ebp), %ecx
	mov	$0, %eax	
	dec	%ebx
t:	inc	%ebx
	cmpb	%cl, (%ebx)
	JZ	found
afterf:	cmpb	$0, (%ebx)
	JNZ	t
	pop	%edx
	pop	%ecx
	pop	%ebx
	leave
	ret
found:	mov	%ebx, %eax
	JMP	afterf

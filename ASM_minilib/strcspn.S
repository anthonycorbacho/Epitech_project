.global strcspn

/*
 int strcspn(char *s, char *charset)
 return the number of char in s before finding the first char present in charset
*/
	
strcspn:
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
	push	%ecx
	JMP	is_in_s2
notf:	pop	%ecx
	inc	%eax
	cmpb	$0, (%ebx)
	JNZ	t
found:	
	pop	%edx
	pop	%ecx
	pop	%ebx
	leave
	ret

is_in_s2:
	movb	(%ebx), %dl
	dec	%ecx
t2:	inc	%ecx
	cmpb	%dl, (%ecx)	
	JZ	found
	cmpb	$0, (%ecx)
	JNZ	t2
	JMP	notf

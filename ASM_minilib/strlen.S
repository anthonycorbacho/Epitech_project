.global strlen

/*
 Strlen
 Reads from a pointer placed on stack
 returns the string len in eax
*/	
strlen:
	push	%ebp
	mov	%esp, %ebp
	push	%ebx
	push	%ecx
	mov	$0, %ecx	
	mov	8(%ebp), %ebx
	xor	%ecx, %ecx
lstr:	cmpb	$0, (%ebx)
	JZ	done
	inc	%ebx
	inc	%ecx
	JMP	lstr
done:	mov	%ecx, %eax
	pop	%ecx
	pop	%ebx	
	leave
	ret

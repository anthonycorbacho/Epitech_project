.global strncmp

strncmp:
	push	%ebp
	mov	%esp, %ebp
	push	%ebx
	push	%ecx
	push	%edx
	mov	8(%ebp), %ebx
	mov	12(%ebp), %edx
	mov	16(%ebp), %ecx
	dec	%ebx
	dec	%edx
	cmp	$0, %ecx
	JZ	done
t:	inc	%ebx
	inc	%edx
	cmpb	$0, (%ebx)
	JZ	done
	cmpb	$0, (%edx)
	JZ	done
	mov	$0, %eax
	movb	(%ebx), %al
	cmpb	%al, (%edx)
	JNE	done
	loop	t
done:
	mov	$0, %eax
	mov	$0, %ecx
	movb	(%ebx), %al
	movb	(%edx), %cl
	sub	%ecx, %eax	
	pop	%edx
	pop	%ecx
	pop	%ebx
	leave
	ret

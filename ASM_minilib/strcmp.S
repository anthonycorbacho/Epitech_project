.global strcmp

strcmp:
	push	%ebp
	mov	%esp, %ebp
	push	%ebx
	push	%ecx
	push	%edx
	mov	8(%ebp), %ebx
	mov	12(%ebp), %edx
	dec	%ebx
	dec	%edx
t:	inc	%ebx
	inc	%edx
	cmpb	$0, (%ebx)
	JZ	done
	cmpb	$0, (%edx)
	JZ	done
	movb	(%ebx), %al
	cmpb	%al, (%edx)
	JZ	t
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

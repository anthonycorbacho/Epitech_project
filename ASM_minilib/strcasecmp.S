.global strcasecmp

	
char_is_alph	:
	push	%ebp
	mov	%esp, %ebp
	mov	8(%ebp), %ebx
	cmp	$65, %ebx
	JL	fail
	cmp	$90, %ebx
	JG	fail
	mov	$1, %eax
	JMP	q
fail:
	mov	$0, %eax
q:	leave
	ret


my_charcasecmp:
	push	%ebp
	mov	%esp, %ebp
	push	12(%ebp)
	call	char_is_alph
	add	$4, %esp
	cmp	$0, %eax
	mov	12(%ebp), %ebx
	JE	g
	add	$32, %ebx
g:	push	%ebx
	push	8(%ebp)
	call	char_is_alph
	add	$4, %esp
	cmp	$0, %eax
	mov	8(%ebp), %ebx
	JE	gg
	add	$32, %ebx
gg:
	pop	%eax
	mov	$0, %edx
	movb	%al, %dl
	mov	%edx, %eax
	mov	$0, %edx
	movb	%bl, %dl
	mov	%edx, %ebx
	sub	%ebx, %eax
	leave
	ret
	
strcasecmp:
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
	push	%ebx
	push	%edx
	mov	$0, %eax
	movb	(%ebx), %al
	push	%eax
	mov	$0, %eax
	movb	(%edx), %al
	push	%eax
	call	my_charcasecmp
	add	$8, %esp
	pop	%edx
	pop	%ebx
	cmp	$0, %eax
	JNZ	done
	cmpb	$0, (%ebx)
	JZ	done
	cmpb	$0, (%edx)
	JZ	done
	JMP	t
done:
	pop	%edx
	pop	%ecx
	pop	%ebx	
	leave
	ret

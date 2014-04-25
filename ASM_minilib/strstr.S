.global strstr

my_strlen_str:
	push	%ebp
	mov	%esp, %ebp
	push	%ebx
	push	%ecx	
	mov	8(%ebp), %ebx
	xor	%ecx, %ecx
lstr:	cmpb	$0, (%ebx)
	JZ	done1
	inc	%ebx
	inc	%ecx
	JMP	lstr
done1:	mov	%ecx, %eax
	pop	%ecx
	pop	%ebx	
	leave
	ret

my_strncmp_str:
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

strstr:
	push	%ebp
	mov	%esp, %ebp
	push	%ebx
	push	%ecx
	push	%edx
	push	12(%ebp)
	call	my_strlen_str
	pop	%edx
	mov	%eax, %edx	/*Save len in edx*/
	mov	8(%ebp), %ebx
b:	cmp	$0, (%ebx)
	JZ	l
	push	%edx		/*Arg push*/
	push	12(%ebp)
	push	%ebx	
	call	my_strncmp_str
	add	$12, %esp	/*Pop args*/
	cmp	$0, %eax
	JZ	p
	inc	%ebx
	JMP	b
l:	xor	%eax, %eax
	JMP	q
p:	mov	%ebx, %eax
q:	pop	%edx
	pop	%ecx
	pop	%ebx
	leave
	ret

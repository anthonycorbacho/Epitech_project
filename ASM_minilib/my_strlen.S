.global mystrlen
	
mystrlen:
	push %ebp
	mov %esp, %ebp
	push %ecx
	mov 8(%ebp), %eax
	mov $0, %ecx	
boucle:	cmpb $0, (%eax)
	JE end
	inc %ecx
	inc %eax
	JMP boucle
end:	mov %ecx, %eax
	pop %ecx
	leave
	ret
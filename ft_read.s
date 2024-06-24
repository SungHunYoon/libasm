section .text
	extern ___error
	global _ft_read

_ft_read:
	mov rax, 0x2000003
	syscall
	jc .err
	ret
.err:
	push rax
	call ___error
	pop r10
	mov [rax], r10
	mov rax, -1
	ret
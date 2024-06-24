section .text
	extern ___error
	global _ft_write

_ft_write:
	mov rax, 0x2000004
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
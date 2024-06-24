section .text
	global _ft_strcpy

_ft_strcpy:
	mov rax, rdi
	mov rcx, rdi
	mov rdx, rsi
.loop:
	cmp byte [rdx], 0
	je .done
	mov r10, [rdx]
	mov [rcx], r10
	inc rcx
	inc rdx
	jmp .loop
.done:
	ret
section .text
	global _ft_strcmp

_ft_strcmp:
	mov rcx, rdi
	mov rdx, rsi
	xor r9, r9
.loop:
	mov al, [rcx]
	mov r10b, [rdx]
	test al, al
	je .done
	cmp al, r10b
	jne .done
	inc rcx
	inc rdx
	jmp .loop
.done:
	sub al, r10b
	movsx rax, al
	ret
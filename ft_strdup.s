global ft_strdup
extern ft_strlen
extern ft_strcpy
extern malloc
extern __errno_location
section .text

ft_strdup:				;rdi = str
	push	rdi
	call	ft_strlen
	mov		rdi, rax
	inc		rdi			;pr le \0
	call	malloc
	cmp		rax, 0
	je		ft_error
	mov		rdi, rax	;dest in call to ft_strcpy
	call	ft_strcpy
	ret

ft_error:
	push	rax
	call	__errno_location
	mov		QWORD [rax], 12
	pop		rax
	ret

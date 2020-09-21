global ft_strcpy

section .text
ft_strcpy:   ;rdi = dest rsi = src
        xor rax, rax
        cmp rsi, 0
        je  return
        jmp copy

copy:
        mov r8b, BYTE [rsi + rax]
        mov BYTE [rdi + rax], r8b
        cmp BYTE [rsi + rax], 0
        je  return
        inc rax
        jmp copy

return:
        mov rax, rdi
        ret
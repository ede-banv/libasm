global ft_strcmp

section .text
ft_strcmp: ;s1 = rdi, s2 = rsi
        xor rax, rax
        jmp ft_compare
        
ft_compare:
        mov r8b, BYTE [rdi + rax]
        cmp r8b, BYTE [rsi + rax]
        jnz check
        cmp r8b, 0
        je ft_pos
        inc rax
        jmp ft_compare

check:
        cmp r8b, BYTE [rsi + rax]
        jl ft_neg
        jmp ft_pos

ft_neg:
        mov rax, -1
        jmp ft_return

ft_pos:
        sub r8b, [rsi + rax]
        cmp r8b, 0
        je ft_return
        mov rax, 1

ft_return:
        ret
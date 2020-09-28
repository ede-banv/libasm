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
        cmp r8b, [rsi + rax]
        je ft_same
        mov rax, 1
        jmp ft_return

ft_same:
        mov rax, 0

ft_return:
        ret
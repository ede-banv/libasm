global ft_read

section .text
ft_read:
        mov rax, 0
        push rdx
        syscall
        pop rdx
        cmp rax, -errno
        je error
        ret

error:
        mov rax, -1
        ret

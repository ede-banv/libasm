global ft_write

section .text
ft_write: 
        mov rax, 1
        push rdx
        syscall
        pop rdx
        cmp rax, -errno
        je erreur
        ret

error:
        mov rax, -1
        ret

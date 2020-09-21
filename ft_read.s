global ft_read
extern __errno_location
section .text

ft_read:
        mov rax, 0
        syscall
        cmp rax, 0
        jl error
        ret

error:
        neg rax ;rax cest la valeur de errno mais on doit le mettre a l'endroit ou errno est
        push rax
        call __errno_location ;nous retourne un pointeur sur errno dans rax
        pop QWORD [rax] ;[]veut dire on regarde a l'interieur de. donc un met la valeur qu'on a pop en 64bit dans le pointeur sur errno qui est dans rax
        mov rax, -1
        ret

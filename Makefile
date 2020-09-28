NA = nasm
CC = gcc
NA_FLAGS = -f elf64

SRCS = ft_write.s ft_strlen.s ft_strcpy.s ft_strcmp.s \
		ft_strdup.s ft_read.s

OBJS	= ${SRCS:.s=.o}
%.o:	%.s
			$(NA) $(NA_FLAGS) $<

NAME = libasm.a
$(NAME)	: ${OBJS}
		ar rcs ${NAME} ${OBJS}

all : ${NAME}

clean :
		rm -f ${OBJS}

fclean : clean
		rm -f ${NAME}

re : fclean all
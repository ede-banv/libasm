#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "libasm.h"

int strlen_test()
{
    printf("***************STRLEN*****************\n");
    printf("str: 'c'est la faute a marie therese'\nmon strlen: %zd\tle vrai: %zd\n\n", ft_strlen("c'est la faute a marie therese"), strlen("c'est la faute a marie therese"));
    printf("str: chaine vide\nmon strlen: %zd\t le vrai: %zd\n\n", ft_strlen(""), strlen(""));
    printf("str: '\\0'\nmon strlen: %zd\tle vrai: %zd\n\n", ft_strlen("\0"), strlen("\0"));
    printf("str: 'lol'\nmon strlen: %zd\tle vrai: %zd\n\n", ft_strlen("lol"), strlen("lol"));
    printf("str: '\\n'\nmon strlen: %zd\tle vrai: %zd\n\n", ft_strlen("\n"), strlen("\n"));
    printf("\n\n");
    return (1);
}

int strcmp_test()
{
    printf("***************STRCMP*****************\n");
    printf("s1: 'Hello'\ts2: 'Hello'\nmon strcmp: %d\t le vrai: %d\n\n", ft_strcmp("Hello", "Hello"), strcmp("Hello", "Hello"));
    printf("s1: ''\ts2: 'Hello'\nmon strcmp: %d\t le vrai: %d\n\n", ft_strcmp("", "Hello"), strcmp("", "Hello"));
    printf("s1: 'Hi there'\ts2: 'Hilarious'\nmon strcmp: %d\t le vrai: %d\n\n", ft_strcmp("Hi there", "Hilarious"), strcmp("Hi there", "Hilarious"));
    printf("s1: ''\ts2: ''\nmon strcmp: %d\t le vrai: %d\n\n", ft_strcmp("", ""), strcmp("", ""));
    printf("s1: 'C'est fou'\ts2: 'C'est mou'\nmon strcmp: %d\t le vrai: %d\n\n", ft_strcmp("C'est fou", "C'est mou"), strcmp("C'est fou", "C'est mou"));
    printf("\n\n");
    return (1);
}

int strcpy_test()
{
    char    dst[100];

    printf("***************STRCPY*****************\n");
    printf("src: \nmy strcpy: %s\tog: %s\n\n", ft_strcpy(dst, "Hello"), strcpy(dst, "Hello"));
    printf("src: ''\nmy strcpy: %s\tog: %s\n\n", ft_strcpy(dst, ""), strcpy(dst, ""));
    printf("src: 'Sup bros and laddies'\nmy strcpy: %s\tog: %s\n\n", ft_strcpy(dst, "Sup bros and laddies"), strcpy(dst, "Sup bros and laddies"));
    printf("src: '4256738'\nmy strcpy: %s\tog: %s\n\n", ft_strcpy(dst, "4256738"), strcpy(dst, "4256738"));
    printf("\n\n");
    return (1);
}

int strdup_test()
{
    char    *dst;

    dst = NULL;
    printf("***************STRDUP*****************\n");
    printf("str: 'lol on va copier ca lo'\nmine: %s\t", dst = ft_strdup("lol on va copier ca lo"));
    printf("og: %s\n\n", dst = strdup("lol on va copier ca lo"));
    printf("str: ''\nmine: %s\t", dst = ft_strdup(""));
    printf("og: %s\n\n", dst = strdup(""));
    printf("str: 'on va fair des folies !!'\nmine: %s\t", dst = ft_strdup("on va fair des folies !!"));
    printf("og: %s\n\n", dst = strdup("on va fair des folies !!"));
    printf("\n\n");
    return (1);
}

int write_test()
{
    printf("***************WRITE*****************\n");
    printf("to print: 'Hello World!'\nmine: ");
    printf("[%zd] ", ft_write(1, "Hello World!", 12));
    printf("\tog: ");
    printf("[%zd]", write(1, "Hello World!", 12));
    printf("\nto print: 'This is a problem'\nmine: ");
    printf("[%zd] ", ft_write(-5, "This is a problem", 18));
    printf("\tog: ");
    printf("[%zd]", write(-5, "This is a problem", 18));
    printf("\nto print: ''\nmine: ");
    printf("[%zd] ", ft_write(1, "", 1));
    printf("\tog: ");
    printf("[%zd]", write(1, "", 1));
    printf("\nto print: ''\nmine: ");
    printf("[%zd] ", ft_write(1, "Libasm", 1));
    printf("\tog: ");
    printf("[%zd]", write(1, "Libasm", 1));
    printf("\n");
    printf("\n\n");
    return (1);
}

int read_test()
{
    char    buffer[100];
    int     fd;
    int     errno;

    errno = 0;
    fd = -1;
    printf("***************READ*****************\n");
    printf("mine :\n");
	printf("\treturn : [%ld] | %d\n", ft_read(fd, buffer, 8), errno);
	errno = 0;
	printf("og :\n");
	printf("\treturn : [%ld] | %d\n", read(fd, buffer, 8), errno);
	errno = 0;
	fd = open("test.txt", O_RDONLY);
	printf("mine :\n");
	printf("\treturn : [%ld] | %d\n", ft_read(fd, buffer, 8), errno);
	close(fd);
	errno = 0;
	fd = open("test.txt", O_RDONLY);
	printf("og :\n");
	printf("\treturn : [%ld] | %d\n", read(fd, buffer, 8), errno);
    printf("\n\n");
    return (1);
}

int main()
{
    if (!strlen_test())
        return (-1);
    if (!strcmp_test())
        return (-1);
    if (!strcpy_test())
        return (-1);
    if (!strdup_test())
        return (-1);
    if (!write_test())
        return (-1);
    if (!read_test())
        return (-1);
}
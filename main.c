#include <unistd.h>
#include <string.h>
#include <stdio.h>

int ft_strlen(char *str);
char *ft_strcpy(char *dest, const char *src);
int ft_strcmp( const char *s1, const char *s2);

int main()
{
    char    dest[15];
    printf("Strlen test: %d\n", ft_strlen("lol"));
    printf("Strcpy test: src: [CKOILEPB]\tres: %s\n", ft_strcpy(dest, "CKOILEPB"));
    printf("Strcmp test: expected: %d\tres %d\n", strcmp("keskialespoto", "keskiaxdxdxd"), ft_strcmp("keskialespoto", "keskiamdxdxd"));
    return (0);
}
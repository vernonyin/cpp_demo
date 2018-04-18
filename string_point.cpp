#include <stdio.h>
#include <string.h>

void Func(char str_arg[100])
{
    printf("%d\n", strlen(str_arg));
    printf("%s\n", str_arg);
}
void Func2(char* str_arg)
{
    printf("%d\n", sizeof(str_arg));
    printf("%s\n", str_arg);
}
char *strcpy2(char *dest, const char *src)
{
//首指针
	char *tmp = dest;

	while ((*dest++ = *src++) != '\0')
		/* nothing */;
	return tmp;
}
int main(void)
{
    char str[] = "Hello";
    printf("%d\n", sizeof(str));
    printf("%d\n", strlen(str));
    char *p = str;
    printf("%d\n", sizeof(p));
    Func(str);
    Func2(str);
}

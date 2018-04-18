#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void Func(char str_arg[2])
{
    int m = sizeof(str_arg);
    int n = strlen(str_arg);
    printf("%d\n", m);
    printf("%d\n", n);
}


void f(char**p){
      *p +=2;
}

int main(void)
{
	char *p="hello";
	//p[1]='E';	
	int i=0;i=(i++);
	printf("p=%s\n",p);
	return 0;
    char str[] = "Hello";
    printf("sizeof = %d\n", sizeof(str));
    printf("strlen = %d\n", strlen(str));
	signed char a=0xe0;
	printf("signed char c=%d\n",a);
	unsigned char c=a;
	printf("unsigned char c=%x\n",c);
    Func(str);
}

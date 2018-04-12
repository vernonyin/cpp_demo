#include <stdio.h>   //sprintf
#include <string.h>  //strcpy
#include <stdlib.h> // malloc sort atoi rand strtoul

int main() {

	char a[] = "hello world";
	char* pt =(char *) malloc(1000);
	//测试strcpy

	strcpy(pt,a);

	printf(a);
	printf(pt);
	return 0;
}




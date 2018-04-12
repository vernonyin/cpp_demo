#include <stdio.h>   //sprintf
#include <string.h>  //strcpy
#include <stdlib.h> // malloc sort atoi rand strtoul

int main() {

	printf("sizeof(char)=%d\n",sizeof(char));
	//char 范围是-128~127 char128=-128，char256=0 unsigned char 500=500-256=244;
	char num=0;
	for(int i=0;i<2000;i++){
		printf("i=%d,char num=%d\n",i,num);
		num++;
	}
	return 0;
}




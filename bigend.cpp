#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void IsBigEndian()
{
	short int a = 0x1122;//十六进制，一个数值占4位
	char b =  *(char *)&a;  //通过将short(2字节)强制类型转换成char单字节，b指向a的起始字节（低字节）
	if( b == 0x11)//低字节存的是数据的高字节数据
	{
		//是大端模式
		printf("big endian\n");
	}
	else
	{
		printf("small endian\n");
		//是小端模式
	}
}
bool foobar(int a, int *b, int **c)
{
    int *p = &a;
    *p = 101;
    *c = b;
    b = p;
    *b = *p;
char *p1="hello"; 
char *p2="hello"; 
printf("p1 addr %lu\n",strlen(p1));
printf("p2 addr %lu\n",p2);
return p1 == p2;

}

int point_test(char *&a){
    printf("a address=%lu\n",a);
    a = (char *)malloc(100);
    printf("a address=%lu\n",a);
} 
void swap(int& a,int& b){
	int c=a;
	a=b;
	b=c;
} 
int main()
{
	int i1=3,i2=5;
	printf("i1=%d,i2=%d\n",i1,i2);
	swap(i1,i2);
	printf("i1=%d,i2=%d\n",i1,i2);
	swap(i1,i2);
	printf("i1=%d,i2=%d",i1,i2);
int ii = 1<<7;
printf("ii <<8 = %d \n",ii);
char *p1="hello";
char *p2="world";
char *p3="a piece of cake";
char *str[]={p1,p2,p3};
printf("%c\n",*(str[0]+1));
    char *a1=NULL;
    printf("a1 address=%lu\n",a1);
    point_test(a1);
    printf("a1 address=%lu\n",a1);
    strcpy(a1,"tt");
    int a = 1;
    int b = 2;
    int c = 3;
    int *p = &c;
    int ret = foobar(a, &b, &p);
    printf("a=%d, b=%d, c=%d, *p=%d\n", a, b, c, *p);
    printf("ret=%d",ret);
return (0);
}
/*
int main(){
	union{
		short int a;
		char c;
} ua;
	ua.a=0x1122;
	printf("union char =%x\n",ua.c);

	IsBigEndian();

}

*/

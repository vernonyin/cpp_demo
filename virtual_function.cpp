#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;

class Test{
public:
    int a;
    int b;
    virtual void fun() {}
    Test(int temp1 = 0, int temp2 = 0)
    {
        a=temp1 ;
        b=temp2 ;
    }
    int getA()
    {
        return a;
    }
    int getB()
    {
        return b;
    }
};

//传指针的引用进来，和swap的两种写法是一毛一样的！！！
void getMemory(char*& p){
	p = (char *)malloc(100);
}

void swap(int& a,int& b){
	int c=a;
	a=b;
	b=c;
}
//指针的指针
void getMemory2(char** p){
	*p = (char *)malloc(100);
}

void swap2(int* a,int* b){
	int c=*a;
	*a=*b;
	*b=c;
}

int main()
{
	unsigned char i=-1;
	printf("unsigned char i=%d\n",i);
	int a=1,b=5;
	char* p=NULL;
	getMemory(p);
	strcpy(p,"hello");
	printf(p);
	swap(a,b);
	printf("a=%d,b=%d\n",a,b);


	getMemory2(&p);
	strcpy(p,"hello2");
	swap2(&a,&b);
	printf("a=%d,b=%d\n",a,b);
	printf(p);



    Test obj(5, 10);
    // Changing a and b
    int* pInt = (int*)&obj;
    *(pInt+0) = 100;
    *(pInt+1) = 200;
    cout << "a = " << obj.getA() << endl;
    cout << "b = " << obj.getB() << endl;
    return 0;
}

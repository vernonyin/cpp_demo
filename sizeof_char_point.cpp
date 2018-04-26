#include<iostream>
using namespace std;
 
class Base
{
public:
    virtual int foo(int x)
    {
        return x * 10;
    }
 
    int foo(char x[14])
    {
        return sizeof(x) + 10;
    }
};
 
class Derived: public Base
{
    int foo(int x)
    {
        return x * 20;
    }
 
    virtual int foo(char x[10])
    {
        return sizeof(x) + 20;
    }
} ;
 
#pragma pack(2)
class BU
{
    typedef char*(*f)(void*);
    typedef char*(*f2)(void*);
    typedef char*(*f3)(void*);
    typedef char*(*f4)(void*);
    typedef char*(*f5)(void*);
}bu;

    typedef char*(*f6)(void*);
int main()
{
  enum{hdd}disk;
	int a=50;
	int* pint = &a; 
pint += 6; 
//	printf("ping=%p",pint);
	printf("ping=%d",pint);
	printf("ping=%d",*pint);
	printf("\n sizeof(enum)=%d\n",sizeof(disk));
	return 0;
	printf("sizeof(BU)=%d\n",sizeof(f6));	
    Derived stDerived;
    Base *pstBase = &stDerived;
 
    char x[10];
    printf("%d\n", pstBase->foo(100) + pstBase->foo(x));
 
    return 0;
}

#include <iostream>
#include <stdio.h>
using namespace std;

/*函数指针用处： 做回调函数 */

int add(int a,int b) {
	return a+b;
}

/* The calling function takes a single callback as a parameter. */
void PrintTwoNumbers(int (*numberSource)(int,int)) {
    int val1= numberSource(1,1);
    int val2= numberSource(2,2);
    printf("%d and %d\n", val1, val2);
}

/* A possible callback */
int overNineThousand(int a,int b) {
    return a+b;
}

/* Another possible callback. */
int meaningOfLife(int a,int b) {
    return a*100+b*100;
}

int func_point(int (*add)(int,int)){
	return add(10,30);
}

int main() {

	//定义一个函数指针
	int (*pf)(int,int);
	pf = &add; //指针初始化
	//函数指针参数
    printf("func_point =%d\n",func_point(pf));

    //函数指针大小，和普通指针一样的
	printf("function point sizeof=%d",sizeof(pf));

	typedef int (*Add)(int,int); //定义一种类型，指针也可以不用
	typedef int (AddNoP)(int,int); //定义一种类型，指针也可以不用
	Add handle = &add;
	AddNoP* handle2 = &add;

	func_point(pf);


	cout << pf(10,40)<<endl; //调用1
	cout << handle(10,60)<<endl; //调用2
	cout << handle2(100,600)<<endl; //调用2

    PrintTwoNumbers(&overNineThousand);
    PrintTwoNumbers(&meaningOfLife);

	class TMyClass
	{
	public:
	   int DoIt(float a, char b, char c){ cout << "TMyClass::DoIt"<< endl; return a+b+c;};
	   int DoMore(int a, int b) const
	         { cout << "TMyClass::DoMore" << endl; return a+b; };

	   /* more of TMyClass */
	};

//	func_point(TMyClass::*DoMore);
	int (TMyClass::*pt2ConstMember)(float, char, char) const = NULL;
	pt2ConstMember = &TMyClass::DoIt; // note: <pt2Member> may also legally point to &DoMore

	// Calling Function using Function Pointer

	(*this.*pt2ConstMember)(12, 1);


	struct C
	{
	    void f(int n) { std::cout<<"c class member function n=" << n << '\n'; }
	};

	struct C2
	{
	    void f(int n) { std::cout<<"c class member function n=" << n << '\n'; }
	};

	//定义 和引用
	void (C::* pttt)(int) = &C::f; // pointer to member function f of class C
	C c;
	(c.*pttt)(1);                  // prints 1
	C2* cp = &c;
	(cp->*pttt)(2);                // prints 2
	return 0;
}




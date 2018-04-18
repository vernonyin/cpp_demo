#include <iostream>
using namespace std;

class Foo
{
public:
        Foo() { cout << "Foo constructor" << endl; }
        Foo(const Foo &foo) { cout << "Foo copy constructor" << endl; }
        ~Foo() { cout << "Foo deconstructor" << endl; }
};

class Bar
{
public:
        Bar() { cout << "Bar constructor" << endl; }
        Bar(const Bar &bar) { cout << "Bar copy constructor" << endl; }
        ~Bar() { cout << "Bar deconstructor" << endl; }
};

class Base
{
public:
        Base() { cout << "Base constructor" << endl; }
        ~Base() { cout << "Base deconstructor" << endl; }
};

class Derived : public Base
{
public:
        Derived() { cout << "Derived constructor without arguments" << endl; }
        Derived(const Foo &foo, const Bar &bar);
        Derived(const Bar &bar, const Foo &foo);
        ~Derived() { cout << "Derived deconstructor" << endl; }

private:
        Bar m_bar;
        Foo m_foo;
};

Derived::Derived(const Foo &foo, const Bar &bar) :
        m_foo(foo),
        m_bar(bar)
{
        cout << "Derived constructor with argument[Foo foo, Bar bar] passed by references" << endl;
}

Derived::Derived(const Bar &bar, const Foo &foo) :
        m_bar(bar),
        m_foo(foo)
{
        cout << "Derived constructor with argument[Bar bar, Foo foo] passed by references" << endl;
}

char* fun22 (char* p)
{
		printf("fun22 p add=%llu\n",&p);
	int i=0;
    return p;
}

void getmemory(char *p)
{
		printf("getmemory p add=%llu\n",&p);
    p=(char*)malloc(100);
		printf("getmemory p add=%llu\n",&p);
}
class A{
};
class B{
    char ch;
    int x;
};
class C{
public:
    void Print(void){}
};
class D
{
public:
    virtual void Print(void){}
};

int main (int argc, char** argv)
{
	printf("sizeof(A)=%d\n",sizeof(A));
	printf("sizeof(B)=%d\n",sizeof(B));
	printf("sizeof(C)=%d\n",sizeof(C));
	printf("sizeof(D)=%d\n",sizeof(D));
        //Foo foo;
        //Bar bar;
const char str1[] = "abc";        
const char str2[] = "abc";
const char *p1 = "abc";
const char *pp2 = "abc";
printf("%d %d %d %d %d %d %d %d %d\n",str1, str2,p1,pp2);
        cout << "test case 1:" << endl;
        Derived deri_1;  //  (1)
		char* p="hello";
		char* p2=NULL;
		printf("p add=%llu\n",&p2);
		p2 = fun22(p2);
		//getmemory(p2);
		printf("p add=%llu\n",&p2);
		printf("strlen(hello)=%d",strlen(p));
return 0;
 		Foo foo;
        Bar bar;
        cout << "test case 2:" << endl;
        Derived deri_2(foo, bar);   //  (2)

        cout << "test case 3:" << endl;
        Derived deri_3(bar, foo);   //  (3)

        cout << "test case end" << endl;

        return 0;
}

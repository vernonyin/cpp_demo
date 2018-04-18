#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
#define Mul(x,y) ++x*++y

class claA{
public:
	claA(int a,int b){
		printf("construct \n");
		_a=a;
		_b=b;
	}
//protected:
	~claA(){
		printf("destroy \n");
	}
private:
    //void* operator new(size_t t){}     // 注意函数的第一个参数和返回值都是固定的  
	int _a;
	int _b;
};

class Singleton
{
public:
    static Singleton* getInstance()
    {
        static Singleton instance;
        return &instance;
    }
	void do_something(){
		cout<<"do something...."<<endl;
	}

protected:
    struct Object_Creator
    {
        Object_Creator()
        {
            cout<<"Object_Creator constructor"<<endl;
            Singleton::getInstance();
        }
    };
    static Object_Creator _object_creator;

    Singleton() {cout<<"Singleton constructor"<<endl;}
    ~Singleton() {}
};
Singleton::Object_Creator Singleton::_object_creator;
  
int main()
{
	Singleton::getInstance()->do_something();
	//claA A(1,1);
	claA* heap = new claA(1,1);
	delete heap;
int a = 1;
int b = 2;
int c = 3;
 int *aa=new int(12);
//free(aa); 
delete (aa); 
printf("%d\n",Mul(a+b,b+c));
	int arr[]={1,2,3,45};
	printf("arr3=%d\n",*(arr+3));
return 0;
}

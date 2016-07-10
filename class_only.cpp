#include <stdio.h>

/* http://blog.csdn.net/hxz_qlh/article/details/13135433
 *
 * http://kelvinh.github.io/blog/2014/04/19/research-on-operator-new-and-delete/
 * 在类内部new一个对象，这个很厉害啊
 * */

class HeapOnly
{
protected:
	HeapOnly(){}
    ~HeapOnly(){}
public:
    static HeapOnly* create()
    {
        return new HeapOnly();
    }
    void destory()
    {
        delete this;
    }
};

class StackOnly
{
private:
    void* operator new(size_t t){}     // 注意函数的第一个参数和返回值都是固定的
    void operator delete(void* ptr){} // 重载了new就需要重载delete
public:
    StackOnly(){}
    ~StackOnly(){}
};

int main2(){
	HeapOnly* a = HeapOnly::create();
	a->destory();
	return 0;
};


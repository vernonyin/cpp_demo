#include <stdio.h>

/* http://blog.csdn.net/hxz_qlh/article/details/13135433
 *
 * http://kelvinh.github.io/blog/2014/04/19/research-on-operator-new-and-delete/
 * �����ڲ�newһ�����������������
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
    void* operator new(size_t t){}     // ע�⺯���ĵ�һ�������ͷ���ֵ���ǹ̶���
    void operator delete(void* ptr){} // ������new����Ҫ����delete
public:
    StackOnly(){}
    ~StackOnly(){}
};

int main2(){
	HeapOnly* a = HeapOnly::create();
	a->destory();
	return 0;
};


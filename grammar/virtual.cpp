//
// Created by yin on 2018/11/12.
//
#include <iostream>
using namespace std;

class Base {

public:

    virtual void f() { cout << "Base::f" << endl; }

    virtual void g() { cout << "Base::g" << endl; }

    virtual void h() { cout << "Base::h" << endl; }

};

int main(){
    typedef void(*Fun)(void);

    Base b;

    Fun pFun = NULL;

    cout << "虚函数表地址：" << (int*)(&b) << endl;

    cout << "虚函数表 — 第一个函数地址：" << (int*)*(int*)(&b) << endl;

// Invoke the first virtual function

    ((Fun)*((int*)*(int*)(&b)+0))(); // Base::f()

    (Fun)*((int*)*(int*)(&b)+1); // Base::g()

    (Fun)*((int*)*(int*)(&b)+2); // Base::h()

    pFun();
    return 0;
}
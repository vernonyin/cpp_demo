//
// Created by yin on 2019-01-26.
//

#include <iostream>
using namespace std;

class Base{
public:
    virtual void print(int a){cout<<"Base print int a"<<endl;}
    virtual void print(char a){cout<<"Base print char a"<<endl;}
    virtual void print(double a,double b){cout<<"Base print double a"<<endl;}
};

class Derived:public Base{
public:
    void print1(int a,int b){cout<<"derived print int a"<<a<<endl;}
};

int main(){
    Derived d;
    d.print(10);
    d.print(2.5,2.5);
    d.print('d');
    return 0;
}
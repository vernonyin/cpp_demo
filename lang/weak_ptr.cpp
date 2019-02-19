//
// Created by yin on 2019-01-28.
//

#include <iostream>
#include <memory>
using namespace std;

class B;

class A{
public:
  shared_ptr<B> bptr;
  ~A(){cout<<"~A"<<endl;}
};

class B{
public:
  //shared_ptr 最好
  weak_ptr<A> aptr;
  ~B(){cout<<"~B"<<endl;}
};

int main(){
  shared_ptr<A> a(new A());
  shared_ptr<B> b(new B());
  a->bptr = b;
  b->aptr = a;
  return 0;
}
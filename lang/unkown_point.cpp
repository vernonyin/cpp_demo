//
// Created by yin on 2019-01-28.
//

#include <iostream>

class Test{
public:
  Test(){
    i=90;
    delete this;
  }
  ~Test(){
    std::cout<<"~Test"<<std::endl;
  }
  void func(){
    std::cout<<"func "<<i<<std::endl;
  }

  void set(int a){
    i = a;
  }


  int i;
};

int main(){
  Test* test = new Test();
  std::cout<<test->i<<std::endl;
  test->set(999);
  test->func();
}
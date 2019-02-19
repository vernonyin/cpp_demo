//
// Created by yin on 2019-01-28.
// 神奇，为什么呢？

#include <iostream>
using namespace std;

class Test{
public:
  static void func1(){cout<<"func1 "<<val1<<endl;}

  void func2(){cout<<"func2 "<<endl;}

  void func3(){cout<<"func3 "<<val1<<endl;}

  void func4(){cout<<"func4 "<<val2<<endl;}

private:
  static int val1;
  int val2;
};

int Test::val1=4;

int main(){
  Test *p =NULL;
  p->func1();//内部转换为：Test::func1()
  p->func2();//内部转换为：Test::func2(NULL);
  p->func3();
  p->func4();
}
//
// Created by yin on 2018/11/19.
//


#include <iostream>

using namespace std;

int g_constructCnt = 0;
int g_copyCnt = 0;
int g_destructCnt = 0;

struct A{
  A(){
    cout<<"construct "<<++g_constructCnt<<endl;
  }
  A(const A& a){
    cout<<"copy "<<++g_copyCnt<<endl;
  }
  ~A(){
    cout<<"destruct "<<++g_destructCnt<<endl;
  }
};

A GetA(){
  return A();
}

void PrintA(A a){
  return ;
}

int main(){
  A a = GetA();
  A b = a;
  PrintA(a);
  return 0;
}

#include <iostream>

using namespace std;

int main(){
  int a= 5;
  //mutable 可以修改值拷贝，但是修改的是副本
  auto check = [a]  () t{
    a = 10;
  };

  check();
  cout<<"a="<<a<<endl;

  return 0;
}
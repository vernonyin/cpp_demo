#include <iostream>

using namespace std;

int main(){

  auto add = [](int a, int b){
    return a+b;
  };

  cout<<"1+2="<<add(1,2)<<endl;

  function<int(int,int)> add2 = [](int a, int b){
    return a+b;
  };

  cout<<"3+4="<<add2(3,4)<<endl;

  return 0;
}
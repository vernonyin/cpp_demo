#include <iostream>

using namespace std;

int main(){
  int x= 5;
  auto check = []() -> bool{
    if(x == 0){
      return false;
    }else{
      return true;
    }
  };

  cout<<"check()="<<check()<<endl;

  return 0;
}
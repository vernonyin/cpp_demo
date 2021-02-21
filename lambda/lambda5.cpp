#include <iostream>
#include <vector>
using namespace std;

int main(){

  vector<int> vt={1,2,3,4,5,6,7,8,9};

  //找第一个
  cout<<"cout = "<<*find_if(vt.begin(),vt.end(),[](int x){
    return  x > 5;
  })<<endl;

  return 0;
}
#include <iostream>
#include <string>
using namespace std;

int main(){

  string s = "1234";


  cout<<sizeof(s.c_str())<<endl;
  cout<<sizeof(s.data())<<endl;
  return 0;
}
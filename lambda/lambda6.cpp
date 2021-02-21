#include <iostream>
#include <vector>
using namespace std;

class C{
public:
    C() {
      cout<<"construct C"<<endl;
    };

    ~C(){
      cout<<"destruct C"<<endl;
    }

    C(const C& c){
      cout<<"const C"<<endl;
    }

    const C& operator=(const C& c){
      cout<<"operator C"<<endl;
      return *this;
    }

    int x;
};

int main(){
  C c1;

  auto f = [=](){
    c1.x;
    cout<<"f function"<<endl;
  };

  f();
  return 0;
}
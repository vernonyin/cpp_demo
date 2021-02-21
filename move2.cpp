//
// Created by yin on 2018/12/3.
//

#include <iostream>
#include <utility>
#include <vector>
#include <string>

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

int main()
{
  C c;
  std::vector<C> v;

//  v.push_back(c);

  v.emplace_back(move(c));
  /*
construct C
const C
destruct C
destruct C
   */
  return 0;
}
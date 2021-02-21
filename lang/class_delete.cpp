//
// Created by yin on 2019-01-26.
//

#include <iostream>

class Base{
public:
     Base()= default ;

    Base(int a){
      printf("base Base()\n");
    }
    ~Base(){
        printf("base ~Base() %d\n",v);
    }

    //禁止
//    Base(const Base& b ) =delete;
    Base(const Base& b ){
      printf("create Base(const Base& b )\n");
    }

    Base& operator=(const Base& b){
      printf("create operator=  \n");
      v = 5;
      return *this;
    }
  int v;
};



int main(){
    Base b=5;//用explicit修饰就不行
    b.v = 1;
    Base b1 = b;
    b1.v = 4;

    b1 = b;

    return 0;
}
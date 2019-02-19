//
// Created by yin on 2019-01-26.
//

#include <iostream>

class Base{
public:
    Base(int a,int b){
        printf("base Base()\n");
    }
    ~Base(){
        printf("base ~Base()\n");
    }
};

class Test{
public:
    Test():b(55+a),a(b+1),c(0),bb(a,b){

    }
    ~Test(){

    }
    int b;
    int c;

    int a;
    Base bb;
};


int main(){
    Test t;
    printf("=============a %d==========\n",t.a);

    printf("=============b %d==========\n",t.b);
    return 0;
}
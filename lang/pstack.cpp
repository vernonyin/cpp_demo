//
// Created by yin on 2019-02-18.
//

#include <iostream>
#include <unistd.h>

using namespace std;

void func1(){
    cout<<"func1"<<endl;
    usleep(100*1000);
}

void func2(){
    cout<<"func2"<<endl;
    usleep(100*1000);
}
void func3(){
    cout<<"func3"<<endl;
    usleep(100*1000);
}
void func4(){
    cout<<"func4"<<endl;
    usleep(100*1000);
}
void func5(){
    cout<<"func5"<<endl;
    usleep(100*1000);
}

int main(){
    while(true){
        func1();
        func2();
        func3();
        func4();
        func5();
    }
    return 0;
}
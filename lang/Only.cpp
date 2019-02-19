//
// Created by yin on 2019-01-23.
//

#include <iostream>

using namespace std;

class HeapOnly{
public:
    static HeapOnly* Create(){
        return new HeapOnly();
    }

    void Delete(){
        delete this;
    }

protected:
    ~HeapOnly(){
        cout<<"~HeapOnly()"<<endl;
    }
    HeapOnly(){
        cout<<"HeapOnly()"<<endl;
    }

    HeapOnly(const HeapOnly& h){
        cout<<"HeapOnly(const HeapOnly& h)"<<endl;
    }

    HeapOnly& operator=(const HeapOnly& h){
        cout<<"operator="<<endl;
        return *this;
    }
};

class StackOnly{
public:
    StackOnly(){
        cout<<"construct"<<endl;
    }
    StackOnly&operator=(const StackOnly& s){
        cout<<"operator ="<<endl;
    }
    StackOnly(const StackOnly& s){
        cout<<"copy construct"<<endl;
    }
    ~StackOnly(){
        cout<<"destruct"<<endl;
    }
private:
    void* operator new(size_t i){
        return nullptr;
    }
    void* operator new[](size_t i){
        return nullptr;
    }
};

int main(){
    HeapOnly* h=HeapOnly::Create();
    h->Delete();
//    HeapOnly h2 = new HeapOnly();


    StackOnly s;
//    StackOnly* s2 = new StackOnly();

    return 0;
}
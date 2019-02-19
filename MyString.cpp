//
// Created by yin on 2019-01-23.
//

#include <iostream>
#include<stdio.h>
using namespace std;
/*问题：
1、strcpy 和memcpy区别
2、初始化为nullptr
3、构造函数有返回值      MyString* MyString(const MyString& ms){
4、private:
    char* buff;
*/

class MyString{
public:
    MyString(const char* c){
        cout<<"MyString 构造函数"<<endl;
        if (c == nullptr){
            buff = nullptr;
            return ;
        }
        buff = (char *)malloc((strlen(c)+1)* sizeof(char));
        strcpy(buff,c);
    }
    virtual  ~MyString(){
        cout<<"MyString 析构函数"<<endl;
        if (buff == nullptr){
            return ;
        }
        free(buff);
        buff = nullptr;
    }
    MyString(const MyString& ms){
        cout<<"MyString 赋值构造函数11"<<endl;
        if(ms.buff == nullptr){
            buff = nullptr;
            return ;
        }
        free(buff);
        buff = (char *)malloc((strlen(ms.buff)+1)* sizeof(char));
        strcpy(buff,ms.buff);
    }

    MyString( MyString& ms){
        cout<<"MyString 赋值构造函数22"<<endl;
        if(ms.buff == nullptr){
            buff = nullptr;
            return ;
        }
        buff = (char *)malloc((strlen(ms.buff)+1)* sizeof(char));
        strcpy(buff,ms.buff);
    }

    MyString& operator=(const MyString& ms){
        cout<<"MyString operator函数"<<endl;
        if(ms.buff == nullptr){
            buff = nullptr;
            return *this;
        }
//        if (this == &ms) return *this;
        char* old =  buff;
        buff = (char *)malloc((strlen(ms.buff)+1)* sizeof(char));
        free(old);
        strcpy(buff,ms.buff);
        return *this;
    }

//    MyString& operator=(const MyString& ms){
//        cout<<"MyString operator函数"<<endl;
//        if(ms.buff == nullptr){
//            buff = nullptr;
//            return *this;
//        }
//        buff = (char *)malloc((strlen(ms.buff)+1)* sizeof(char));
//        strcpy(buff,ms.buff);
//        return *this;
//    }
    void Print(){
        if (buff == nullptr){
            cout<<"MyString 打印为空"<<endl;
        }else{
            cout<<"MyString 打印:"<<buff<<endl;
        }
    }

private:
    char* buff;
};

int main(){
    char * p ="sss2";
    MyString s(p);
    s.Print();


    s = s;

    return 0;
    MyString s1(NULL);
    s1.Print();

    MyString s2(NULL);
    s2 = s;
    s2.Print();
    const MyString& s3= s2;
    MyString s4(s3);
    MyString s5(s4);
//    s3 = s2 = s1;
//    s3.Print();
    return 0;
}
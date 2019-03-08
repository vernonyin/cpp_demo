//
// Created by yin on 2019-02-20.
//

#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;

char *strncpy2(char *dst, const char *src,size_t n)
{
//首指针
    char *temp = dst;
    while (n-- && (*dst++ = *src++)){
        cout<<dst<<endl;
    }
    return temp;
}

void *memcpy2(void *dest, const void *src, size_t n)
{
    char *dp = (char*)dest;
    const char *sp = (char*)src;
    while (n--)
        *dp++ = *sp++;
    return dest;
}

int main(void)
{
    char a='\0';
    if(a &&  1){
        cout<<"\0 == 0"<<endl;
    }
    char str1[] = "Hello";
    char str2[]="world";
//    strncpy(str1,str2,3);
//    strncpy2(str1,str2,3);
    memcpy2(str1,str2,3);
    cout<<str1<<endl;
    cout<<str2<<endl;
}

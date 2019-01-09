//
// Created by yin on 2019-01-08.
//

#include <string.h>
#include <stdlib.h>
#include <cmath>
#include <vector>

char* replaceSpace(char * str){
    char* head = str;
    int len=0;
    while(*str != '\0'){
        len += *str == ' ' ? 3:1;
        str++;
    }
    char * newStr = (char *)malloc(len);
    int i=0;
    printf("====len %d===\n",len+1);
    while(*head != '\0'){
        if (*head == ' '){
            newStr[i++]='%';
            newStr[i++]='2';
            newStr[i++]='0';
        }else{
            newStr[i++]=*head;
        }
        head ++;
    }
    newStr[i]='\0';
    printf("newStr:%s\n",newStr);
    str = newStr;
    return newStr;

}
int main() {
    char *s = "he llo ";
    char * n = replaceSpace(s);
    printf("new str:%s\n",n);
    return 0;
}
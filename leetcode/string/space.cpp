#include <string>
#include <stdlib.h>
#include <cmath>
#include <vector>

using namespace std;
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

int replace(char str[10],int len);
//下面三种是一样的声明方式：
int replace1(char* str,int len){

    return replace(str,len);
}
int replace2(char str[],int len){
    return replace1(str,len);
}

int replace(char str[],int len){
    if (str== NULL || len ==0){
        return 0;
    }
    int space = 0;
    for(int i=0;i<len;i++){
        if (str[i] == ' '){
            space++;
        }
    }
    int newLen = len+space*2-1;
    for (int i=len-1;i>=0;i--){
        if (str[i] != ' '){
            str[newLen--]=str[i];
        }else{
            str[newLen--]='0';
            str[newLen--]='2';
            str[newLen--]='%';
        }
    }
    return len+space*2;
}
int main() {
    //构造方法1
//    char s[100]="ab c";
    //直接malloc 需要手动free 需要异常判断
    char* s = (char *)malloc(100);
    if (s == NULL) {

    }
    strcpy(s,"ab c");
    int t = replace2(s,strlen(s));
    printf("new str:%s\n",s);
    free(s);
    return 0;
}
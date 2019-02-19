//
// Created by yin on 2019-01-26.
//

#include <iostream>
//异常返回0，还是-1？
//溢出了怎么办呢？

class solution {
public:
    int stoi(char *str) {
        if (str == nullptr ){
            return 0;
        }
        int digit = 1;
        int pos = 0;
        if(str[pos] == '-'){
            digit = -1;
            pos++;
        }else if (str[pos] == '+'){
            pos++;
        }
        long res = 0;
        for(int i=pos;i<strlen(str);i++){
            if(str[i] <'0' || str[i]>'9'){
                return 0;
            }
            res = res*10+(str[i]-'0');
        }
        return (int)res*digit;
    }

};

int main() {
    char str[1000] = "-100";
    solution s;
    int i = s.stoi(str);
    printf("after:%s=%d", str,i);
}
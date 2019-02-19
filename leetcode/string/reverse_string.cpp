//
// Created by yin on 2019-01-24.
//

#include <iostream>
//中间有几个空格？

class solution {
public:
    int reverse_string(char *str) {
        int len = strlen(str)-1;
        swap(str, 0, len);
        for (int i = 0; i < len;) {
            int end = i;
            while (str[end] != '\0' && str[end] != ' ') {
                end++;
            }
            //!!! 注意单个的情况
            if (end > len+1) {
                break;
            }
            swap(str, i, end-1);
            i = end+1;// i要往后加一
        }
    }

    void swap(char *c, int start, int end) {
        if (start < 0 || end < 0 || start == end) {
            return;
        }
        while (start < end) {
            char tmp = c[start];
            c[start] = c[end];
            c[end] = tmp;
            start++;
            end--;
        }
    }

    char* reversN(char* c,int n){
        if(n <= 0 || n>=strlen(c) ){
            return c;
        }
        int len = strlen(c);
        swap(c,0,len-1);
        swap(c,0,len-n-1);
        swap(c,len-n,len-1);

    }

};

int main() {
    char str[1000] = "abcd";
    solution s;
    s.reversN(str,0);
    printf("after:%s", str);
    s.reversN(str,1);
    printf("after:%s", str);
    s.reversN(str,2);
    printf("after:%s", str);
    s.reversN(str,3);
    printf("after:%s", str);
    s.reversN(str,4);
    printf("after:%s", str);
    s.reversN(str,400);
    printf("after:%s", str);
}
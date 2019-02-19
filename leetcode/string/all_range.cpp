//
// Created by yin on 2019-01-24.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;
//中间有几个空格？

class solution {
public:
    vector<string> Permutation(string str) {
        vector<string> res;

    }


    vector<string> recur(char* first,char* end){
        vector<string> res;
        if(*end == '\0'){
            return res;
        }
        for(int i=0;i<strlen(end);i++){
            char tmp = *first;
            *first++ = *end;
        }

        return res;
    }

};

int main() {
    char str[1000] = "abc";
    solution s;
    s.reverse_string(str);
    printf("after:%s", str);
}
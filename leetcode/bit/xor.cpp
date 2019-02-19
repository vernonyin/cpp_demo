//
// Created by yin on 2019-01-28.
// 将二进制倒数第M位的前N位取反


#include <iostream>

class solution{
public:
    // 11111
    int MtoN(int val,int m,int n){
        int t = 1<<n;
        int tt = t-1;
        int ttt = tt<<m;
        return val^ttt;
    }

};
int main(){

}
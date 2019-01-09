//
// Created by yin on 2018/11/14.
//

#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;

class Solution {
public:
    //统计1的位数
    // https://leetcode.com/problems/number-of-1-bits
    int hammingWeight(uint32_t n) {
        //普通做法
        int count=0;
        while(n  >0){
            if (n %2)
                count++;
            n = n>>1;
        }
        return count;

    }

    int hammingWeightBit(uint32_t n){
        int count = 0;
        while(n){
            count++;
            n &=(n-1);
        }
        return count;
    }


    // 判断2的n次方 https://leetcode.com/problems/power-of-two
    bool isPowerOfTwo(int n) {
        if(n<=0) return false;
        return (n&(n-1)) == 0;
    }
};

int main(){
    Solution s;
    printf("5 bit =%d \n",s.hammingWeight(5));
    printf("5 bit =%d \n",s.hammingWeightBit(5));
    printf("1024 bit =%d \n",s.hammingWeight(1024));
    printf("1024 bit =%d \n",s.hammingWeightBit(1024));
    printf("7 bit =%d \n",s.hammingWeight(7));
    printf("7 bit =%d \n",s.hammingWeightBit(7));
    printf("16 bit =%d \n",s.hammingWeight(16));
    printf("16 bit =%d \n",s.hammingWeightBit(16));

    int b = 5 & -5;
    printf("b =%d \n",b);
    return 0;
}
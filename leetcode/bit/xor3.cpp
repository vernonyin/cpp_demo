//
// Created by yin on 2019-01-28.
// 找出数组中除了三个数字只出现一次外，其余数字均出现偶数次



#include <iostream>

class solution {
public:
    // 11111
    int find3(int val[], int n) {
        int odd = 0, even = 0;
        int odd_c = 0, even_c = 0;
        for (int i = 0; i < 32; i++) {
            odd = even = odd_c = even_c = 0;
            int bit = 1 << i;
            for (int j = 0; j < n; j++) {
                if (val[j] & bit) {
                    even ^= val[j];
                    even_c++;
                } else {
                    odd ^= val[j];
                    odd_c++;
                }
            }

            if (even > 0 && even_c & 1) {
                return even;
            }
            if (odd > 0 && odd_c & 1) {
                return odd;
            }
        }
    }

};

int main() {

}
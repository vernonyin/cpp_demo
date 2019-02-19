//
// Created by yin on 2019-01-14.
//

#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;


class BitMap {
public:
    int nbit;
    char *bits;

public:
    BitMap(int n) {
        nbit = n;
        bits = (char *) calloc((n / 8 + 1) * sizeof(char),0);
        memset(bits,0,(n / 8 + 1) * sizeof(char));
    }

    void set(int k) {
        int i = k / 8;
        int j = k % 8;
        bits[i] |= 1 << j;
    }

    bool get(int k) {
        int i = k / 8;
        int j = k % 8;
        return bits[i] && 1 << j;
    }

    void print() {
        for (int i = 0; i < nbit / 8 + 1; i++) {
            for (int j = 0; j < 8; j++) {
                if (bits[i] & 1 << j) {
                    printf("%d\n", i * 8 + j);
                }
            };
        }
    }
};

int main() {
    BitMap b(1000);
    b.set(5);
    b.set(15);
    b.set(1000);
    b.set(999);
    b.print();

    printf("%d\n",b.get(999));
    printf("%d\n",b.get(888));
}
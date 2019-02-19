//
// Created by yin on 2019-01-28.
// 找出数组中除了三个数字只出现一次外，其余数字均出现偶数次
#include <iostream>

using namespace std;

typedef int (* PFunc)(int a,int b);

int cal1(int a, int b, PFunc f) {
  return f(a, b);
}

int cal(int a, int b, int (*op)(int, int)) {
  return op(a, b);
}

int add(int a, int b) {
  return a + b;
}

int minus1(int a, int b) {
  return a - b;
}

int main() {
  int a = 6, b = 3;
  cout << cal1(a, b, add) << endl;
  cout << cal1(a, b, minus1) << endl;
}
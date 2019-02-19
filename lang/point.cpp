//
// Created by yin on 2019-01-28.
// 找出数组中除了三个数字只出现一次外，其余数字均出现偶数次
#include <iostream>

using namespace std;

int find(char *s, char ch, char *sub) {
  for (int i = 0; *(s + i) != '\0'; i++) {
    if (*(s + i) == ch) {
      strcpy(sub, s + i + 1);
//            sub = s+i+1;
      return i;
    }
  }
}

int find2(char *s, char ch, char **sub) {
  for (int i = 0; *(s + i) != '\0'; i++) {
    if (*(s + i) == ch) {
            *sub = s+i+1;
      return i;
    }
  }
}

int main() {
  char fullName[] = {"Michael#Jordan"};
  char givenName[99];

  int cnt = find(fullName, '#', givenName);

  char *givenName2;
  int cnt2 = find2(fullName, '#', &givenName2);
  cout << givenName << endl;
}
//
// Created by yin on 2019-01-14.
//

#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

class Solution {
public:
    int myAtoi(string str) {
      int sign =1,i=0;
      long res =0;
      while(str[i] == ' ') {i++; }

      if(str[i] == '-' || str[i] == '+'){
        if(str[i] == '-') {
          sign = -1;
        }
        i++;
      }

      while(str[i] >= '0' && str[i] <= '9'){
        res = res* 10 + (str[i] -'0');

        if(res*sign > INT_MAX) return INT_MAX;
        if(res*sign < INT_MIN) return INT_MIN;

        i++;
      }

      return res*sign;
    }
};
int main() {
  Solution s;


//  printf("%d\n",s.myAtoi("42"));
  printf("%d\n",s.myAtoi("   -42"));
}
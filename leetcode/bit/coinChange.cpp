//
// Created by yin on 2018/12/4.
//

#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <cmath>
#include <vector>
#include <deque>
#include <set>

using namespace std;

class Singleton
{
public:
  static Singleton* GetInstance()
  {
    static Singleton instance;
    return &instance;
  }

protected:
  // 辅助代理类
  struct Object_Creator
  {
    Object_Creator()
    {
      Singleton::GetInstance();
    }
  };
  static Object_Creator _object_creator;

  Singleton() {}
  ~Singleton() {}
};

Singleton::Object_Creator Singleton::_object_creator;


class Solution {
public:
  //相当于走台阶dp https://leetcode.com/problems/coin-change/submissions/
  //dp方程：dp[i]=min(dp[i-coins[j])+1
  //时间复杂度：n*m
  int coinChange(vector<int> &coins, int amount) {
    int Max = amount + 1;
    vector<int> dp(amount + 1, Max);
    dp[0] = 0;
    for (int i = 0; i <= amount; i++) {
      for (int j = 0; j < coins.size(); j++) {
        if (coins[j] <= i) {
          dp[i] = min(dp[i], dp[i - coins[j]] + 1);
        }
      }
    }
    return dp[amount] > amount ? -1 : dp[amount];
  }

};

int myatoi(const char *str) {
  int sign = 1, base = 0, i = 0;
  while (str[i] == ' ') { i++; }
  if (str[i] == '-' || str[i] == '+') {
    sign = 1 - 2 * (str[i++] == '-');
  }
  while (str[i] >= '0' && str[i] <= '9') {
    if (base >  INT_MAX / 10 || (base == INT_MAX / 10 && str[i] - '0' > 7)) {
      if (sign == 1) return INT_MAX;
      else return INT_MIN;
    }
    base  = 10 * base + (str[i++] - '0');
  }
  return base * sign;
}

int main() {
  printf("atoi=%f",myatoi("3.14"));
  Solution s;
  vector<int> v{1, 2, 5};
  int num = s.coinChange(v, 11);
  printf("num=%d\n",num);
}
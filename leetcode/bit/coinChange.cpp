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

    vector<int> dp(amount+1,amount+1);
    dp[0] = 0;

    for(int i = 0; i < amount; i++){
      for(int j=0; j < coins.size(); j++){
        if(coins[j] <= i){
          dp[i] = min(dp[i-coins[j]]+1,dp[i]);
        }
      }
    }

    return dp[amount] > amount ? -1 : dp[amount];

  }

  //25
    int waysToChange(int n) {
      return _waysToChange(4,n);
    }

    int _waysToChange(int x,int y){
      vector<int> vc={1,5,10,25};
      if(--x >0 ){
        int res = 0 ;
        for(int i = 0 ;i < y/vc[x] ; i++){
          res += _waysToChange(i,y-i*vc[x]);
        }
        return res;
      }else{
        return 1;
      }
  }


    int coinChange2021(vector<int>& coins, int amount) {
      vector<int> dp(amount+1,amount+1);
      dp[0] = 0;
      for(int i = 0; i <= amount; i ++){
        for(int j = 0; j < coins.size(); j++){
          if(i >= coins[j])
              dp[i] = min(dp[i],dp[i-coins[j]]+1);
        }
      }

      return dp[amount] == 0 ? -1 : dp[amount];
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
//  printf("atoi=%f",myatoi("3.14"));
  Solution s;
//  vector<int> v{1, 2, 5};
  vector<int> v{2};
//  int num = s.coinChange(v, 11);

//  int num = s.coinChange2021(v,11);
  int num = s.coinChange2021(v,3);
  printf("num=%d\n",num);

}
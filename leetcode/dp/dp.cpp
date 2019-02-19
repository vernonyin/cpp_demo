//
// Created by yin on 2018/11/25.
//

//
// Created by yin on 2018/11/15.
//
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <vector>
#include<stdlib.h>
#include <sys/malloc.h>

using namespace std;

const int ROW = 8;
const int COL = 8;

class Solution {
public:
  int dp(int nums[ROW][COL], int row, int col) {
    if (!validSquare(nums, row, col))
      return 0;
    if (isAtEnd(nums, row, col))
      return 1;
    return dp(nums, row + 1, col) + dp(nums, row, col + 1);
  }

  bool validSquare(int nums[ROW][COL], int row, int col) {
    if (nums[row][col] == 1) {
      return false;
    }
    if (row >= ROW || col >= COL) {
      return false;
    }
    return true;
  }

  bool isAtEnd(int nums[ROW][COL], int row, int col) {
    if (row == ROW - 1 && col == COL - 1) {
      return true;
    } else {
      return false;
    }
  }

  //动态规划
  int dp2(int nums[ROW][COL], int row, int col) {
    int opt[ROW][COL];

    for (int i = 0; i < ROW; i++)
      opt[i][0] = 1;
    for (int j = 0; j < COL; j++)
      opt[0][j] = 1;
    for (int i = 1; i < ROW; i++) {
      for (int j = 1; j < COL; j++) {
        if (nums[i][j] == 0) {
          opt[i][j] = opt[i - 1][j] + opt[i][j - 1];
        } else {
          opt[i][j] = 0;
        }
      }
    }

    return opt[ROW - 1][COL - 1];

  }

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

  //爬楼梯
  int climbStairs(int n) {
    if (n<=2) return n;
    int a1=1,a2=1;
    int total=2;
    for (int i=2;i<n;i++){
      a1 = a2;
      a2 = total;
      total=a1+a2;
    }
    return total;
  }

  int minimumTotal(vector<vector<int> > &triangle) {
      int depth = triangle.size();
      vector<vector<int > > dp;
      for (int i=0;i<triangle.size();i++){
          vector<int> tmp;
          for(int j=0;j<triangle[i].size();j++){
              tmp.push_back(0);
          }
          dp.push_back(tmp);
      }
      for(int i=0;i<triangle[depth-1].size();i++){
          dp[depth-1][i] = triangle[depth-1][i];
      }
      for(int i=depth-2;i>=0;i--){
          for (int j=0;j<triangle[i].size();j++){
              dp[i][j] = min(dp[i+1][j],dp[i+1][j+1])+triangle[i][j];
          }
      }

      return dp[0][0];

//    vector<int> mini = triangle[triangle.size()-1];
//    for ( int i = triangle.size() - 2; i>= 0 ; --i )
//      for ( int j = 0; j < triangle[i].size() ; ++ j )
//        mini[j] = triangle[i][j] + min(mini[j],mini[j+1]);
//    return mini[0];


    vector<int> mini = triangle[triangle.size()-1];
    for (int i=triangle.size()-2;i>= 0;i--){
      for (int j=0;j<triangle[i].size();j++){
        mini[j]= min(mini[j],mini[j+1])+ triangle[i][j];
      }
    }
    return mini[0];
  }

  //https://time.geekbang.org/course/detail/130-69783
  // 最长上升子序列
    int lengthOfLIS(vector<int>& nums) {
  //[10,9,2,5,3,7,101,18]
    vector<int> lis;
    for(int i=0;i<nums.size();i++){
      auto pos = std::lower_bound(lis.begin(),lis.end(),nums[i]);
      if (pos == lis.end()){
        lis.push_back(nums[i]);
      }else{
        *pos = nums[i];
      }
    }
    return lis.size();
    }

    int minDistance(string word1, string word2) {
      int l1 = word1.length();
      int l2 = word2.length();
      vector<vector<int>> dp(l1+1,vector<int>(l2+1,0));
      for(int i=0;i<l1;i++){
        dp[i][0] = i;
      }
      for(int j=0;j<l2;j++){
        dp[0][j] = j;
      }
      for(int i=1;i<=l1;i++){
        for(int j=1;j<=l2;j++){
          if (word1[i-1] == word2[j-1]){
            dp[i][j]=dp[i-1][j-1];
            continue;
          }else{
            dp[i][j] = min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]))+1;
          }
        }
      }
      return dp[l1][l2];
    }

    //股票买卖 121 只能买卖1次
    int maxProfit(vector<int>& prices) {
      if (prices.size() == 0 ) return 0;
      int min=prices[0];
      int profit=0;
      for(int i=0,size=prices.size();i<size;i++){
        if (prices[i] < min){
          min = prices[i];
        }
        else if (prices[i] > min && prices[i]-min >profit){
          profit = prices[i]-min;
        }
      }
      return profit;
    }

  //股票买卖 122 可以买卖无数次 第一天买第二天卖
  int maxProfit122(vector<int>& prices) {
    int profit=0;
    for(int i=0,size=prices.size();i<size-1;i++){
      if(prices[i]<prices[i+1]){
        profit += prices[i+1]-prices[i];
      }
    }
    return profit;
  }

  //股票买卖 123 可以买卖2次
  int maxProfit123(vector<int>& prices) {

  }

  //股票买卖 188 可以买卖k次
  int maxProfit188(vector<int>& prices) {
    int profit=0;
    for(int i=0,size=prices.size();i<size-1;i++){
      if(prices[i]<prices[i+1]){
        profit += prices[i+1]-prices[i];
      }
    }
    return profit;
  }

  int maxProduct(vector<int>& nums) {
    int imin =nums[0], imax = nums[0];
    int res = nums[0];
    for (int i=1,size=nums.size();i<size;i++){
      if (nums[i]<0){
        swap(imin,imax);
      }
      printf("%d\n",nums[i]);
      imin = min(nums[i],nums[i]*imin);
      imax = max(nums[i],nums[i]*imax);

      res = max(res,imax);
    }
    return res;
  }
//[-2,1,-3,4,-1,2,1,-5,4]
//最大连续和
  int maxSubArray(vector<int>& nums) {
    int cur=nums[0];
    int Max = nums[0];
    for (int i=1,size=nums.size();i<size;i++){
      if(cur >0){
        cur = cur+nums[i];
      }else{
        cur = nums[i];
      }
      Max = max(Max,cur);
    }
    return Max;

//    vector<int> dp(nums.size());
//    dp.push_back(nums[0]);
//    int Max = nums[0];
//    for (int i=1,size=nums.size();i<size;i++){
//      if(dp[i-1] >0){
//        dp[i] = dp[i-1]+nums[i];
//      }else{
//        dp[i] = nums[i];
//      }
//      Max = max(Max,dp[i]);
//    }
//    return Max;
  }

  int majorityElement(vector<int>& nums) {
    int res=nums[0];
    int count=1;
    for (int i=1,size=nums.size();i<size;i++){
      if (count == 0){
        res = nums[i];
        count = 1;
      }else if(nums[i] == res){
        count++;
      }else{
        count--;
      }
    }
    return res;
  }

  };

int main() {
    Solution s;
    vector<vector<int > > dp;
    for (int i=0;i<2;i++){
        vector<int> tmp;
        for(int j=0;j<2;j++){
            tmp.push_back(i);
        }
        dp.push_back(tmp);
    }

    s.minimumTotal(dp);


  int a[8][8] = {
          {0, 0, 0, 0, 0, 0, 0, 0},
          {0, 0, 1, 0, 0, 0, 1, 0},
          {0, 0, 0, 0, 1, 0, 0, 0},
          {1, 0, 1, 0, 0, 1, 0, 0},
          {0, 0, 1, 0, 0, 0, 0, 0},
          {0, 0, 0, 1, 1, 0, 1, 0},
          {0, 1, 0, 0, 0, 1, 0, 0},
          {0, 0, 0, 0, 0, 0, 0, 0},
  };

  vector<int> vv={-2,1,-3,4,-1,2,1,-5,4};
  int num000 = s.maxSubArray(vv);
  //[7,1,5,3,6,4]
  // word1 = "horse", word2 = "ros"
  int num0 = s.minDistance("horse","ros");
  printf("num0=%d\n", num0);
  vector<int> v={10,9,2,5,3,7,101,18};
  int num1 = s.lengthOfLIS(v);
  printf("num2=%d\n", num1);

  int num2 = s.climbStairs(3);
  printf("num2=%d\n", num2);
  int num = s.dp2(a, 0, 0);
  printf("num=%d\n", num);
  return 0;
}
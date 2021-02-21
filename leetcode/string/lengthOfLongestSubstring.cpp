//
// Created by yin on 2019-01-26.
//

#include <iostream>
//异常返回0，还是-1？
//溢出了怎么办呢？

class solution {
public:
    int lengthOfLongestSubstring(string s) {
      int sz = s.size();
      vector<int> dp(sz,0);
      dp[0] = 1;

      for(int i = 1; i < sz ;i++){
        int len = dp[i-1];
        dp[i] = dp[i-1]+1;
        for(int j = 1; j<= len; j++){
          if(s[i-j] == s[i]){
            dp[i] = i-j+1;
            break;
          }
        }
      }
      int res = 0;
      for(int i = 0 ; i <sz;i++){
        res = max(res,dp[i]);
      }
      return res;
    }

};

int main() {
    string str = "abcabcbb";
    solution s;
    int i = s.lengthOfLongestSubstring(str);
    printf("after:%s=%d", str,i);
}
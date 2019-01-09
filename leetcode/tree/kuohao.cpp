
//
// Created by yin on 2018/11/14.
//

#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <vector>

using namespace std;

class Solution {
public:
  //生成括号
  vector<string> generateParenthesis(int n) {
    vector<string> vs;
    _gen("", vs, n, n);
    return vs;
  }

  //错误1：vector传引用
  void _gen(string ret, vector<string>& s, int left, int right) {
    if (left == 0 && right == 0) {
      s.push_back(ret);
      return;
    }
    if (left > 0) {
      _gen(ret + "(", s, left - 1, right);
    }
    if (left < right) {
      _gen(ret + ")", s, left , right-1);
    }
  }
};

int main() {
  Solution s;
  vector<string> v = s.generateParenthesis(2);
  for(int i=0;i<v.size();i++){
    printf("=========%s\n",v[i].c_str());
  }


  return 0;
}
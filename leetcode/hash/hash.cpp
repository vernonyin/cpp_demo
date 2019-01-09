//
// Created by yin on 2018/11/14.
//


//
// Created by yin on 2018/11/14.
//
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <vector>
#include <unordered_map>
#include <hashtable>

using namespace std;

class Solution {
public:
  //返回两个数组的交集
  vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    vector<int> ret;
    unordered_map<int,int> m;
    for(int i=0;i<nums1.size();i++){
      m[nums1[i]]+=1;
    }
    for(int i=0;i<nums2.size();i++){
      // 判断>0 而不是==1
      if(m[nums2[i]] >0){
        ret.push_back(nums2[i]);
        m[nums2[i]] -=1;
      }
    }
    return ret;
  }
};


void foo(char a[100], int cnt[256]) {
  memset(cnt, 0, sizeof(cnt));
  while (*a !='\0'){
    ++cnt[*a];
    ++a;
  }
}
int main() {
  char a[100]="口袋购物 abc";
  int cnt[256] ;
  foo(a,cnt);
  for (char c ='a'; c<='z';++c) {
    printf("%c; %d\n", c, cnt[c]);
  }
  return  0;
}

int main2() {
  Solution s;
//  [4,9,5]
//  [9,4,9,8,4]
  vector<int> v1{4,9,5};
  vector<int> v2{9,4,9,8,4};
  vector<int> v = s.intersect(v1,v2);
  for(int i=0;i<v.size();i++){
    printf("=========%d\n",v[i]);
  }

  return 0;
}
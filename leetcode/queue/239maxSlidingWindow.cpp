//
// Created by yin on 2019-02-09.
//

//
// Created by yin on 2019-02-09.
//
#include <iostream>
#include <vector>
#include <deque>

using namespace std;

class Solution {
public:
  vector<int> maxSlidingWindow(vector<int> &nums, int k) {
    vector<int> res;
    deque<int> dq;

    for(int i=0; i< nums.size(); i++){
      while(dq.size() >0 && nums[dq.back()] < nums[i]){
        dq.pop_back();
      }
      if(dq.size() > 0 && i - dq.front() >= k){
        dq.pop_front();
      }
      dq.push_back(i);

      if(i+1 >= k){
        res.push_back(nums[dq.front()]);
      }
    }
    return res;
//
//    deque<int> dq;
//    vector<int> res;
//    for (int i = 0; i < nums.size(); i++) {
//
//      while (!dq.empty() && nums[dq.back()] < nums[i]) {
//        dq.pop_back();
//      }
//      dq.push_back(i);
//      //关键pop
//      if (dq.front() <= i - k)
//        dq.pop_front();
//      if (i < k - 1)
//        continue;
//
//      cout << dq.size() << endl;
//      res.push_back(nums[dq.front()]);
//    }
//
//    return res;
  }
};

int main() {
  Solution s;
  vector<int> nums = {1,3,1,2,0,5};
  //[3,3,2,5]
  vector<int> res = s.maxSlidingWindow(nums, 3);
  return 0;
}
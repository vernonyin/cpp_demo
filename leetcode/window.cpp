//
// Created by yin on 2018/11/7.
//

#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <cmath>
#include <vector>
#include <deque>

using namespace std;
class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> ans;
        for (int i=0;i<nums.size();i++){
            //   vector<int> v{2,3,4,2,6,2,5,1};
            //{16,14,12,10,8,6,4};
            //问题：下标判断
            if (!dq.empty()){
                printf("i %d,front %d \n",i,dq.front());
            }

            if (i> k && dq.front() <=i- k) {
                dq.pop_front();
            }
            //后面丢弃
            while(!dq.empty() && nums[i] >= nums[dq.back()]){
                dq.pop_back();
            }
            dq.push_back(i);
            if (i >= k-1){
                ans.push_back(nums[dq.front()]);
            }
        }
        return ans;
    }
};

int main() {
    Solution s;
//    vector<int> v{2,3,4,2,6,2,5,1};
    vector<int> v{16,14,12,10,8,6,4};
    //使用下标来标注！！！
    s.maxSlidingWindow(v,5);
}
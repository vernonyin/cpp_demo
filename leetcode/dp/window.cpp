//
// Created by yin on 2018/11/7.
//

#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <cmath>
#include <vector>
#include <deque>
#include <set>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        deque<int> dq;
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++) {
            //   vector<int> v{2,3,4,2,6,2,5,1};
            //{16,14,12,10,8,6,4};
            //问题：下标判断
            if (!dq.empty()) {
                printf("i %d,front %d \n", i, dq.front());
            }

            if (i > k && dq.front() <= i - k) {
                dq.pop_front();
            }
            //后面丢弃
            while (!dq.empty() && nums[i] >= nums[dq.back()]) {
                dq.pop_back();
            }
            dq.push_back(i);
            if (i >= k - 1) {
                ans.push_back(nums[dq.front()]);
            }
        }
        return ans;
    }


    vector<int> maxSlidingWindow2(vector<int> &nums, int k) {
        deque<int> window;
        vector<int> res;
        for (int i = 0; i < nums.size(); i++) {
            //删除
            while (window.size() > 0 && nums[window.back()] < nums[i]) {
                window.pop_back();
            }

            //插入
            window.push_back(i);
            //
            if (i - window.front() >= k) {
                window.pop_front();
            }
            if (i+1 >= k) {
                res.push_back(nums[window.front()]);
            }
        }
        return res;
    }

    int maxProduct(vector<int>& nums) {
        if(nums.size() == 0) return 0;

        int res = nums[0];
        int curMax = nums[0];
        int curMin = nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i] < 0){
                swap(curMax,curMin);
            }

            curMax = max(nums[i],curMax*nums[i]);
            curMin = max(nums[i],curMin*nums[i]);

            res = max(res,curMax);
        }

        return res;
    }
};

int main() {
    Solution s;
//    vector<int> v{2,3,4,2,6,2,5,1};
    vector<int> v{-2,3,-4};
    //使用下标来标注！！！
//    s.maxSlidingWindow2(v, 1);
    cout<<s.maxProduct(v)<<endl;
}
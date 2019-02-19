//
// Created by yin on 2018/11/14.
//

#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <vector>
#include <unordered_map>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
public:

    int maxProduct(vector<int> &nums) {
        if (nums.size() == 0){
            return 0;
        }
        int iMin = iMax = nums[0];
        for(int i=0;i<nums.size();i++){
            iMin = min
        }
    }

    // 3 -4 6
    int MaxSubArray(vector<int> nums){
        int curSum = totalSum = 0;
        for(int i=0;i<nums.size();i++){
            if (arr[i] >0){
                curSum += nums[i];
            }else{
                curSum = nums[i];
            }
            totalSum = max(totalSum ,curSum);
        }
        return totalSum;
    }
};

int main(){

}
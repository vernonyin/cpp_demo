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
    //统计1的位数
    // https://leetcode.com/problems/two-sum/discuss/13/Accepted-C%2B%2B-O(n)-Solution
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> res;
        unordered_map<int, int> hash;
        map<int,int> mp;
        for (int i = 0; i < numbers.size(); i++) {
            int f = target - numbers[i];
            if (hash.find(f) != hash.end()) {
                res.push_back(hash[f]);
                res.push_back(i);
                return res;
            }
            hash[numbers[i]] = i;
        }

        return res;
    }

};

int main() {
    map<string,vector<int>> mp;
    vector<int>  vt = mp["sss"];
    for (int i=0;i<vt.size();i++){
        cout<<"fff"<<endl;
    }
    return 0;
    Solution s;
    vector<int> v = {1, 2, 4, 6, 7, 7};
    auto res = s.twoSum(v, 8);
    printf("1 bit=%d\n", res.size());

    int b = 5 & -5;
    printf("b =%d \n", b);
    return 0;
}
//
// Created by yin on 2019-02-19.
//
//
// Created by yin on 2019-02-19.
//
#include <unordered_map>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>


using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& num) {

      vector<vector<int> > res;

      std::sort(num.begin(), num.end());


      for (int i = 0; i < num.size(); i++) {

        int target = -num[i];
        int front = i + 1;
        int back = num.size() - 1;

        while (front < back) {

          int sum = num[front] + num[back];

          // Finding answer which start from number num[i]
          if (sum < target)
            front++;

          else if (sum > target)
            back--;

          else {
            vector<int> triplet(3, 0);
            triplet[0] = num[i];
            triplet[1] = num[front];
            triplet[2] = num[back];
            res.push_back(triplet);

            // Processing duplicates of Number 2
            // Rolling the front pointer to the next different number forwards
            while (front < back && num[front] == triplet[1]) front++;

            // Processing duplicates of Number 3
            // Rolling the back pointer to the next different number backwards
            while (front < back && num[back] == triplet[2]) back--;
          }

        }

        // Processing duplicates of Number 1
        while (i + 1 < num.size() && num[i + 1] == num[i])
          i++;

      }

      return res;
//
//      sort(nums.begin(),nums.end());
//         vector<vector<int>> res;
//
//         //1 1 2
//         for(int i=0; i< nums.size(); i++){
//             int target = -nums[i];
//             int l = i+1;
//             int r = nums.size()-1;
//             while(l < r){
//                 if(nums[l] + nums[r] < target){
//                     ++l;
//                 }else if(nums[l] + nums[r] > target){
//                     --r;
//                 }else{
//                     res.push_back({nums[i],nums[l],nums[r]});
//                     while(l < r && nums[l] == nums[l+1]){
//                         ++l;
//                     }
//                     while(l < r && nums[r] == nums[r-1]){
//                         --r;
//                     }
//                 }
//             }
//             while(i+1 < nums.size() && nums[i] == nums[i+1]){
//                 i++;
//             }
//         }
//         return res;
//
//        sort(nums.begin(), nums.end());
//        vector<vector<int>> res;
//        for (unsigned int i=0; i<nums.size(); i++) {
//            if ((i>0) && (nums[i]==nums[i-1]))
//                continue;
//            int l = i+1, r = nums.size()-1;
//            while (l<r) {
//                int s = nums[i]+nums[l]+nums[r];
//                if (s>0) r--;
//                else if (s<0) l++;
//                else {
//                    res.push_back(vector<int> {nums[i], nums[l], nums[r]});
//                    while (nums[l]==nums[l+1]) l++;
//                    while (nums[r]==nums[r-1]) r--;
//                    l++; r--;
//                }
//            }
//        }
//        return res;
    }

    vector<vector<int>> threeSum2021(vector<int>& nums) {

      //3.[0,0]
      vector<vector<int>> res;
      set<vector<int>>  st;
      int sz =  nums.size();
      if(sz <= 2){
        return res;
      }
      sort(nums.begin(),nums.end());

      for(int i = 0; i < sz-2 ;i++){
        //避免重复
        if( i >= 1 && nums[i] == nums[i-1]){
          continue;
        }
        unordered_map<int,int> mp;
        for(int j = i+1; j < sz ; j++){
          if(mp.count(nums[j]) == 0 ){
            mp[-nums[i]-nums[j]] = 1;
          }else{
            vector<int> tp = {nums[i],-nums[i]-nums[j],nums[j]};
            st.insert(tp);
          }
        }
      }
      for(auto a : st){
        res.push_back(a);
      }
      return res;
    }
};

int main(){
    Solution s;
    vector<int> vec = {0,0,0};
    string str ="abc";
    cout<< "str.size()="<<str.size()<<endl;
    cout<< "str.length()="<<str.length()<<endl;
    s.threeSum2021(vec);
    return 0;
}

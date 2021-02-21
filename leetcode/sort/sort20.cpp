//
// Created by yin on 2020/7/15.
//
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> sortArray(vector<int> &nums) {
      qsort(nums, 0, nums.size() - 1);
      return nums;
    }

    // 1 4 3 2 6
    void qsort(vector<int> &nums, int left, int right) {
      if (left >= right) return;
      //选择一个中间值
      int pivot = nums[left + (right - left) / 2];
      int l = left;
      int r = right;
      while (l <= r) {
        while (nums[l] < pivot)
          l++;
        while (nums[r] > pivot)
          r--;

        if (l > r) {
          break;
        }

        int tmp = nums[l];
        nums[l] = nums[r];
        nums[r] = tmp;
        l++;
        r--;
      }
      printf("====%d,%d====\n",l,r);
      qsort(nums, left, r);
      qsort(nums, l, right);
    }

    void qsort2(vector<int> &nums, int left, int right) {
      if (left >= right) return;
      //选择一个中间值
      int pivot = nums[left + (right - left) / 2];
      int l = left;
      int r = right;
      while (l <= r) {
        if (nums[l] < pivot) {
          l++;
        } else if (nums[r] > pivot) {
          r--;
        } else {
          int tmp = nums[l];
          nums[l] = nums[r];
          nums[r] = tmp;
          l++;
          r--;
        }
      }

      qsort(nums, left, r);
      qsort(nums, l, right);
    }
};

int main() {
  Solution s;
  vector<int> vec = {5, 1, 1, 2};
//  vector<int> vec = {-1,2,-8,-10};
  s.sortArray(vec);
}
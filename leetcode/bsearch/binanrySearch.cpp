//
// Created by yin on 2018/11/15.
//
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    int search(vector<int> &nums, int target) {
        int i = 0, j = nums.size() - 1;
        while (i <= j) {
            int mid = i + (j - i) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] > target) {
                j = mid;
            } else {
                i = mid;
            }
        }
        return -1;
    }

    //考虑大整数 2147395599
    int mySqrt(int x) {
        if (x <= 1) return 1;
        int a = 0, b = x;
        while (a <= b) {
            int mid = a + (b - a) / 2;
            if (x / mid == mid) {
                return mid;
            } else if (x / mid < mid) {
                b = mid - 1;
            } else {
                a = mid + 1;
            }
            //不需要了
//      if (b - a == 1) {
//        return a;
//      }
        }
        return a;
    }

    double mySqrt2(int x) {
        double min = 0;
        double max = x;
        while (max - min > 0.0001) {
            double mid = min + (double) (max - min) / 2;
            double d2 = mid * mid;
            if (abs(d2 - x) < 0.0001) {
                return mid;
            } else if (d2 < x) {
                min = mid;
            } else {
                max = mid;
            }
        }
        return min;
    }
};

int main() {
    Solution s;
    vector<int> v{-1, 0, 5};
    printf("%d\n", s.search(v, -1));
    printf("64=%f\n", s.mySqrt2(2));
    return 0;
}
//
// Created by yin on 2019-02-18.
//

#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdlib.h>
#include <cmath>
#include <vector>

using namespace std;


//取三个位的中位数
int Median3(int *A, int left, int right) {
    int center = (left + right) / 2;
    if (A[left] > A[center])
        swap(A[left], A[center]);
    if (A[left] > A[right])
        swap(A[left], A[right]);
    if (A[center] > A[right])
        swap(A[center], A[right]);

    swap(A[center], A[left]);     //将基准Pivot藏到右边

    return A[left];
}

void quicksortMy1(int arr[], int l, int r) {
    if (l >= r) {
        return;
    }
    int left = l;
    int right = r;
    int pivot = Median3(arr, l, r);
    while (left < right) {
        while (left < right && arr[right] >= pivot) {
            right--;
        }
        arr[left] = arr[right];
        while (left < right && arr[left] <= pivot) {
            left++;
        }
        arr[right] = arr[left];
    }
    arr[left] = pivot;
    if (l < left - 1) {
        quicksortMy1(arr, l, left - 1);
    }
    if (left + 1 < r) {
        quicksortMy1(arr, left + 1, r);
    }
}

template<typename T>
void func(T t) {
    cout << t << endl;
}

int main() {
    int arr[] = {4, 2, 6, 3, 5, 6, 4, 67, 3, 2};
    quicksortMy1(arr, 0, (sizeof(arr) / sizeof(int)) - 1);
    func("hello world");

    for (auto i : arr) {
        cout << i << " ";
    }
    return 0;
}
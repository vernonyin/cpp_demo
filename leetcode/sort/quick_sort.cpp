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
    int pivot = arr[l];//Median3(arr, l, r);
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

#include <iostream>
using namespace std;

void _quicksort(int arr[],int l,int r){
    if(l >= r) return ;

    int left = l;
    int right = r;
    int pivot = arr[l];
    while(left < right){
        while(left < right && arr[right] >= pivot){
            right--;
        }
        arr[left] = arr[right];
        while(left < right && arr[left] <= pivot){
            left++;
        }
        arr[right] = arr[left];
    }
    arr[left] = pivot;
    if(l < left-1){
        _quicksort(arr,l,left-1);
    }
    if(left+1 < r){
        _quicksort(arr,left+1,r);
    }
}

void quicksort666(int arr[],int length){
    _quicksort(arr,0,length-1);
}
//int main() {
//    cout << "Hello World!" << endl;
//}

void quicksort(int arr[],int l,int r){
    if(l >= r) return ;
    int left = l;
    int right = r;
    int pivot = arr[l];
    while(left < right){
        while(left < right && arr[right] >= pivot){
            right--;
        }
        arr[left] = arr[right];
        while(left < right && pivot >= arr[left]){
            left++;
        }
        arr[right] = arr[left];
    }
    arr[left] = pivot;
    if(l < left-1){
        quicksort(arr,l,left-1);
    }
    if(left+1 < r){
        quicksort(arr,left+1,r);
    }
}

int main() {
    int arr[] = {4, -2,2, 6, 3,99, 5, 6, 4, 67, 3, 2};
    quicksort666(arr, (sizeof(arr) / sizeof(int)) );

    for (auto i : arr) {
        cout << i << " ";
    }
    return 0;
}
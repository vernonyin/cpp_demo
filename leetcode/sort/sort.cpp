//
// Created by yin on 2018/12/13.
//

#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <cmath>
#include <vector>


void shell_sort(int arr[], int len) {
  int gap, i, j;
  int temp;
  for (gap = len >> 1; gap > 0; gap >>= 1)
    for (i = gap; i < len; i++) {
      temp = arr[i];
      for (j = i - gap; j >= 0 && arr[j] > temp; j -= gap)
        arr[j + gap] = arr[j];
      arr[j + gap] = temp;
    }
}


int main(){
  int arr[]={4,2,6,3,5,6,4,67,3,2};
  shell_sort(arr,sizeof(arr)/sizeof(int));
  return 0;
}
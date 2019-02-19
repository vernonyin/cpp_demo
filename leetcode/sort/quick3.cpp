//
// Created by yin on 2019-02-19.
//

#include<cstdio>
#include<algorithm>
using namespace std;
#define MAXN 110

void Swap(int *a, int *b){
    int temp;
    temp = *b;
    *b = *a;
    *a = temp;
}
//插入排序
void insertion_sort(int *a, int n) {
    int i, j;
    int temp;
    for (i = 1;i < n;i++) {
        temp = a[i];
        for (j = i; j > 0 && a[j - 1] > temp; j--)
            a[j] = a[j - 1];
        a[j] = temp;
    }
}


void Qsort(int *A, int left, int right){
    int pivot, cutoff, low, high;
    cutoff = 3;                      //定义cutoff, 当数据量小于cutoff时候，用插入排序

    if(1 <= right - left){     //如果序列元素充分多，进入快排
        pivot = Median3(A, left, right);
        low = left;
        high = right - 1;
        while(1){
            while(A[++low] < pivot);
            while(A[--high] > pivot);
            if(low < high)
                Swap(&A[low], &A[high]);
            else break;
        }
        Swap(&A[low], &A[right - 1]);
        Qsort(A, left, low - 1);
        Qsort(A, low + 1, right );
    }
    else
        insertion_sort(A + left, right - left + 1);
}

int main(void){
//    int A[MAXN];
//    scanf("%d", &N);
//    for(int i = 0; i < N; ++i)
//        scanf("%d", &A[i]);
    int A[] = {4,2,6,3,5,6,4,67,3,2};
    int N = 10;
    for(int i = 0 ; i < N; ++i)
        printf("%d ", A[i]);
    printf("\n");
    Qsort(A, 0, N - 1);
    for(int i = 0 ; i < N; ++i)
        printf("%d ", A[i]);
    return 0;
}
//============================================================================
// Name        : t.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <algorithm>
#include <memory>
#include<string>
using namespace std;

extern "C" int func();

int AdjustArray(int s[], int l, int r) //返回调整后基准数的位置
		{
	int i = l, j = r;
	int x = s[l]; //s[l]即s[i]就是第一个坑
	while (i < j) {
		// 从右向左找小于x的数来填s[i]
		while (i < j && s[j] >= x)
			j--;
		if (i < j) {
			s[i] = s[j]; //将s[j]填到s[i]中，s[j]就形成了一个新的坑
			i++;
		}

		// 从左向右找大于或等于x的数来填s[j]
		while (i < j && s[i] < x)
			i++;
		if (i < j) {
			s[j] = s[i]; //将s[i]填到s[j]中，s[i]就形成了一个新的坑
			j--;
		}
	}
	//退出时，i等于j。将x填到这个坑中。
	s[i] = x;

	return i;
}

void quick_sort1(int s[], int l, int r) {
	if (l < r) {
		int i = AdjustArray(s, l, r); //先成挖坑填数法调整s[]
		quick_sort1(s, l, i - 1); // 递归调用
		quick_sort1(s, i + 1, r);
	}
}

//快速排序
void quick_sort(int s[], int l, int r) {
	if (l < r) {
		//Swap(s[l], s[(l + r) / 2]); //将中间的这个数和第一个数交换 参见注1
		int i = l, j = r, x = s[l];
		while (i < j) {
			while (i < j && s[j] >= x) // 从右向左找第一个小于x的数
				j--;
			if (i < j)
				s[i++] = s[j];

			while (i < j && s[i] < x) // 从左向右找第一个大于等于x的数
				i++;
			if (i < j)
				s[j--] = s[i];
		}
		s[i] = x;
		quick_sort(s, l, i - 1); // 递归调用
		quick_sort(s, i + 1, r);
	}
}

void QuickSort(int data[], int lo, int hi) {
	int pivot, l, r, temp;
	l = lo;
	r = hi;
	pivot = data[(lo + hi) / 2]; //取中位值作为分界值
	while (l < r) {
		while (data[l] < pivot)
			++l;
		while (data[r] > pivot)
			--r;
		if (l >= r)
			break;
		temp = data[l];
		data[l] = data[r];
		data[r] = temp;
		++l;
		--r;
	}
	if (lo <= r)
		QuickSort(data, lo, l - 1);
	if (l < hi)
		QuickSort(data, r + 1, hi);
}


bool IsBigEndian()
{
    int a =1 ;
    if(((char*)&a)[0] ==1)
        return true ;
    else
        return false ;
}



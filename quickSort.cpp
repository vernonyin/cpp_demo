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

int AdjustArray(int s[], int l, int r) //���ص������׼����λ��
		{
	int i = l, j = r;
	int x = s[l]; //s[l]��s[i]���ǵ�һ����
	while (i < j) {
		// ����������С��x��������s[i]
		while (i < j && s[j] >= x)
			j--;
		if (i < j) {
			s[i] = s[j]; //��s[j]�s[i]�У�s[j]���γ���һ���µĿ�
			i++;
		}

		// ���������Ҵ��ڻ����x��������s[j]
		while (i < j && s[i] < x)
			i++;
		if (i < j) {
			s[j] = s[i]; //��s[i]�s[j]�У�s[i]���γ���һ���µĿ�
			j--;
		}
	}
	//�˳�ʱ��i����j����x�������С�
	s[i] = x;

	return i;
}

void quick_sort1(int s[], int l, int r) {
	if (l < r) {
		int i = AdjustArray(s, l, r); //�ȳ��ڿ�����������s[]
		quick_sort1(s, l, i - 1); // �ݹ����
		quick_sort1(s, i + 1, r);
	}
}

//��������
void quick_sort(int s[], int l, int r) {
	if (l < r) {
		//Swap(s[l], s[(l + r) / 2]); //���м��������͵�һ�������� �μ�ע1
		int i = l, j = r, x = s[l];
		while (i < j) {
			while (i < j && s[j] >= x) // ���������ҵ�һ��С��x����
				j--;
			if (i < j)
				s[i++] = s[j];

			while (i < j && s[i] < x) // ���������ҵ�һ�����ڵ���x����
				i++;
			if (i < j)
				s[j--] = s[i];
		}
		s[i] = x;
		quick_sort(s, l, i - 1); // �ݹ����
		quick_sort(s, i + 1, r);
	}
}

void QuickSort(int data[], int lo, int hi) {
	int pivot, l, r, temp;
	l = lo;
	r = hi;
	pivot = data[(lo + hi) / 2]; //ȡ��λֵ��Ϊ�ֽ�ֵ
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



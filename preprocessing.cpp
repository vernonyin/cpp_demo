/*
 * preprocessing.cpp
 * Ԥ��������
 *  Created on: 2016��5��21��
 *      Author: John
 */

#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <exception>
#include <time.h>
#include <stdio.h>
#include <iostream>
using namespace std;


int sum5(int a){
	return a;
};

int main_pre() {
	/* Ԥ������� */
	cout << "FILE:" << __FILE__ << endl;
	cout << "LINE:" << __LINE__ << endl;
	cout << "DATE:" << __DATE__ << endl;
	cout << "TIME:" << __TIME__ << endl;

	/* define do while(0) ����*/
	#define DELETE_POINTER(p)       \
		do                          \
		{                           \
			if(NULL != p)           \
				delete p;           \
			p = NULL;               \
		}while(0)

	char* p;
	DELETE_POINTER(p);
	/* �Ƴ�һ��define */
	#undef DELETE_POINTER
	char c='4';
	int b=c;
	/* �������� �������ʽ */
	#if b!=2
		int a=1;
	#else
		int a=2;
	#endif
	cout<<"a="<<a<<endl;

	/* �Ƿ��� */
	#ifndef DELETE_POINTER
	#define DELETE_POINTER 1
		//...
	cout<<"delete_pointer:"<<endl;
	#endif

	/* #a ʵ����������������� cool
	 * define ĩβ������;���õĵط���*/
	#define PRINT(a) printf("the "#a" value\n")
	PRINT(ABC);

	/* ʵ�ֱ������ͺ�������ƴ�ӵ�ƴ�ӣ�����cool */
	#define ADD_TO_SUM(sum_number,value) \
		sum##sum_number += value

	#define ADD_TO_SUM2(sum_number,value) \
		sum##sum_number(value)

	int sum4=1;
	ADD_TO_SUM(4,25);
	cout<<"sum4:"<<sum4<<",ADD_TO_SUM2:"<<ADD_TO_SUM2(5,25)<<endl;

}


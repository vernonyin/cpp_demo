/*
 * preprocessing.cpp
 * 预处理命令
 *  Created on: 2016年5月21日
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
	/* 预定义符号 */
	cout << "FILE:" << __FILE__ << endl;
	cout << "LINE:" << __LINE__ << endl;
	cout << "DATE:" << __DATE__ << endl;
	cout << "TIME:" << __TIME__ << endl;

	/* define do while(0) 妙用*/
	#define DELETE_POINTER(p)       \
		do                          \
		{                           \
			if(NULL != p)           \
				delete p;           \
			p = NULL;               \
		}while(0)

	char* p;
	DELETE_POINTER(p);
	/* 移除一个define */
	#undef DELETE_POINTER
	char c='4';
	int b=c;
	/* 条件编译 常量表达式 */
	#if b!=2
		int a=1;
	#else
		int a=2;
	#endif
	cout<<"a="<<a<<endl;

	/* 是否定义 */
	#ifndef DELETE_POINTER
	#define DELETE_POINTER 1
		//...
	cout<<"delete_pointer:"<<endl;
	#endif

	/* #a 实现输出变量名！！！ cool
	 * define 末尾都不加;调用的地方加*/
	#define PRINT(a) printf("the "#a" value\n")
	PRINT(ABC);

	/* 实现变量名和函数名的拼接的拼接！！！cool */
	#define ADD_TO_SUM(sum_number,value) \
		sum##sum_number += value

	#define ADD_TO_SUM2(sum_number,value) \
		sum##sum_number(value)

	int sum4=1;
	ADD_TO_SUM(4,25);
	cout<<"sum4:"<<sum4<<",ADD_TO_SUM2:"<<ADD_TO_SUM2(5,25)<<endl;

}


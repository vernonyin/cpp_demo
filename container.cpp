/*
 * container.cpp
 *
 *  Created on: 2016��5��21��
 *      Author: John
 */

#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <exception>
#include <stdio.h>
#include <iostream>
using namespace std;


int main11()
{
	/* ���򼯺� Q:ʲôʱ��ʹ�������� */
	unordered_map<int,string> map1={{1,"a"}};
	map<int,string> map2={{1,"a"}};

	/* Ԫ�ز���
	 * ���ڲ��ظ�������count��һ�����ظ��Ļ�count��������*/
	map1.count(2);
	if (map1.find(2) == map1.end()){
		printf("no find 2\n");
	}

	/* set���� */
	set<int> set1={1,4,6,4,3,2};

	/* map���������� pair���� Ҳ�е� */
	pair<int,string> pair1={2,"b"};
	map1.insert({2,"b"});


	//auto beg=map1.lower_bound(1);
	/* ������ʱ���� c++11 */
//	if(map2.emplace(pair1)){
//
//	}
	//auto beg=map1.lower_bound(1);

	printf("map1 size=%d\n",map1.size());
	for(auto i:map1){
		printf("first=%d,second=%s\n",i.first,i.second.c_str());
	}
}

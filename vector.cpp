/*
 * vector.cpp
 *
 *  Created on: 2016��5��20��
 *      Author: John
 */
//todo Ϊʲôû��.h
#include <vector>
#include <map>
#include <exception>
#include <stdio.h>
#include <algorithm>
#include <complex.h>
using namespace std;


/* http://www.cnblogs.com/dudupig123/archive/2010/08/04/1792352.html
 *
 * */
int main1()
{
uint32_t
	/* vector ��ʼ����ʽ*/
	vector<int> v1={9,2,3,5,7};
	/* assign ��ֵ*/
	vector<int> v2;
	v2.assign(v1.begin(),v1.end());

	/* ɾ�� */
	v2.erase(v2.begin());
	/*�԰���Ϊʲô����auto�أ�Ҫ���ڽ�����˼��*/
	for(auto &i : v2)
		printf("%d",i);

	for(vector<int>::iterator it=v1.begin();it!=v1.end();it++){
		printf("%d",*it);
	}
	/* vector��size���Զ��ɱ������� 1 2 4 8 16 32 ...*/
	for(int i = 0;i<100;i++){
		printf("i=%d,size=%d\n",i,v1.capacity());
		v1.push_back(i);
	}
	/* ������������reserve��Ԫ�ص��ڴ�ռ䣬�����ı������е�Ԫ������,�������µ���shrink_to_fit */
	v1.reserve(1000);
	v1.shrink_to_fit();
	printf("size=%d\n",v1.capacity());

	/* []Խ�粻һ���ᱨ��at�ᱨ��Ҫ��ô������ !!!!!!!!*/
	/* at ����ȫ*/
	try{
		v1.at(10000);
	}
	catch(exception& e){
		printf("size=%s\n",e.what());
	}
	find(v1.begin(),v1.end(),2);

	/* �ı�size */
	/* printf���л�������С���⣬��Ȼ�ᱻ���ǣ���Ҫ����\n  !!!!!!!!!!!!!!*/
	v1.resize(10000);

	/* ��ȡ��һ�������һ���ķ���*/
	int& f=v1.front(),e=v1.back() ;
	f=10;
	printf("max=%d %d\n",f,e);
	printf("max=%d\n",v1.max_size());

}

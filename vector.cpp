/*
 * vector.cpp
 *
 *  Created on: 2016年5月20日
 *      Author: John
 */
//todo 为什么没有.h
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
int main()
{
	/* vector 初始化方式*/
	vector<int> v1={9,2,3,3,5,7};


	for(auto it=v1.begin();it!=v1.end();it++){
		printf("v1==before==%d\n",*it);
	}

	for(auto it=v1.begin();it!=v1.end();it++){
		if(*it == 3){
			v1.erase(it);
		}
	}

	vector<int>::iterator iter =v1.begin()+2;
	v1.erase(iter);//注:这里真的不建议这么写

	for(auto it=v1.begin();it!=v1.end();it++){
		printf("v1==after==%d\n",*it);
	}

	std::vector<int>  my_container;
	for (int i = 0; i < 10; ++i) {
	     my_container.push_back(i);
	}

//
//	std::vector<int>::iterator it = my_container.begin();
//	for (;it != my_container.end(); it++) {
//	    if (*it%4  == 1) {
//	    	printf("erase \n");
//	         my_container.erase(it);
////	         it++;
//		    	printf("*it=%d\n",*it);
//	     }
//	}

//	for (;it != my_container.end(); ) {
//		    if (*it%2  == 1) {
//		    	it =  my_container.erase(it);
//		     }else{
//		    	 it++;
//		     }
//		}

	return 0;
	/* assign 赋值*/
	vector<int> v2;
	v2.assign(v1.begin(),v1.end());

	/* 删除 */
	v2.erase(v2.begin());
	/*对啊，为什么不用auto呢，要善于接受新思想*/
	for(auto &i : v2)
		printf("%d",i);

	for(vector<int>::iterator it=v1.begin();it!=v1.end();it++){
		printf("%d",*it);
	}
	/* vector的size是自动成倍增长的 1 2 4 8 16 32 ...*/
	for(int i = 0;i<100;i++){
		printf("i=%d,size=%d\n",i,v1.capacity());
		v1.push_back(i);
	}
	/* 分配至少容纳reserve个元素的内存空间，并不改变容器中的元素数量,不能往下调整shrink_to_fit */
	v1.reserve(1000);
//	v1.shrink_to_fit();
	printf("size=%d\n",v1.capacity());

	/* []越界不一定会报错，at会报错，要怎么捕获呢 !!!!!!!!*/
	/* at 更安全*/
	try{
		v1.at(10000);
	}
	catch(exception& e){
		printf("size=%s\n",e.what());
	}
	find(v1.begin(),v1.end(),2);

	/* 改变size */
	/* printf会有缓冲区大小问题，不然会被覆盖，需要都加\n  !!!!!!!!!!!!!!*/
	v1.resize(10000);

	/* 获取第一个或最后一个的方法*/
	int& f=v1.front(),e=v1.back() ;
	f=10;
	printf("max=%d %d\n",f,e);
	printf("max=%d\n",v1.max_size());

}

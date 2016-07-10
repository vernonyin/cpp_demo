/*
 * container.cpp
 *
 *  Created on: 2016年5月21日
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
	/* 无序集合 Q:什么时候使用无序呢 */
	unordered_map<int,string> map1={{1,"a"}};
	map<int,string> map2={{1,"a"}};

	/* 元素查找
	 * 对于不重复的容器count都一样，重复的话count会做更多*/
	map1.count(2);
	if (map1.find(2) == map1.end()){
		printf("no find 2\n");
	}

	/* set类型 */
	set<int> set1={1,4,6,4,3,2};

	/* map迭代器就是 pair类型 也行的 */
	pair<int,string> pair1={2,"b"};
	map1.insert({2,"b"});


	//auto beg=map1.lower_bound(1);
	/* 不存在时插入 c++11 */
//	if(map2.emplace(pair1)){
//
//	}
	//auto beg=map1.lower_bound(1);

	printf("map1 size=%d\n",map1.size());
	for(auto i:map1){
		printf("first=%d,second=%s\n",i.first,i.second.c_str());
	}
}

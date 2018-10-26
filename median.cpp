/*
 * reverse.cpp
 *
 *  Created on: 2018年4月19日
 *      Author: Administrator
 */

#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <cmath>
using namespace std;

 int median(int a,int b,int c){
	if(a < b)
		if(b < c)
			return b;
		else if( a < c)
			return c;
		else
			return a;
	else if (a < c)
		return a;
	else if (b < c)
		return c;
	else
		return b;
}

inline int median2(int a,int b,int c){
	if( a> b && b> c)
		return b;
	else if (c > b && b> a)
		return b;
	else if( b> a && a> c)
		return a;
	else if ( c>a && a>b)
		return a;
	else 
		return b;
}
int main() {
struct zskiplistNode {
	int a;
    struct zskiplistLevel {
        unsigned int span;
    } level[0];
	int b;
}; 
	printf("sizeof(arr)=%d\n",sizeof(struct zskiplistNode));
return 0;
	int a=1,b=2,c=3;
	for(int i=0;i<100000000;i++){
		a = rand();
		b = rand();
		c = rand();
		median2(a,b,c);	
	}
	printf("end\n");
	return 0;
}



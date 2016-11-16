/*
 * snprintf.cpp
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


int main_snprin()
{
	/* strcpy() sprintf() strcat() 存在安全隐患， 其对应的安全版为：
strncpy() snprintf() strncat() */
	char* p =new char[100];
	snprintf(p,40,"sdfasdfasdf3333333333333333333333333333333333333333333333333333333333333333333333333");
	printf("%s",p);
}

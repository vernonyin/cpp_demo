/*
 * snprintf.cpp
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


int main_snprin()
{
	/* strcpy() sprintf() strcat() ���ڰ�ȫ������ ���Ӧ�İ�ȫ��Ϊ��
strncpy() snprintf() strncat() */
	char* p =new char[100];
	snprintf(p,40,"sdfasdfasdf3333333333333333333333333333333333333333333333333333333333333333333333333");
	printf("%s",p);
}

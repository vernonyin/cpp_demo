/*
 * string.cpp
 *
 *  Created on: 2016年6月4日
 *      Author: John
 */


#include <map>
#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;


char *strncpy1(char *s1, const char *s2, size_t n) {
	while(n>0 && (*s1++ = *s2++)){
		--n;
	}
	return s1;
	char *s = s1;
	while (n > 0 && *s2 != '\0') {
		*s++ = *s2++;
		--n;
	}
	while (n > 0) {
		*s++ = '\0';
		--n;
	}
	return s1;
}

int main_string(int argc, char *argv[]) {

	int iNum = 444;
	/* 字符串转换
	 * http://en.cppreference.com/w/cpp/string/basic_string/to_string
	 *
	string str = std::to_string(iNum);
	float f = stof(str);
	cout<<str<<endl;
	cout<<"float:"<<f<<endl; */

	char *buf = new char[1];
	strcpy(buf, "Good News!"); /* 给数组赋字符串 遇到\0就停止 */
	memcpy(buf, "Good News!", 9); /* 给数组赋字符串 遇到\0就不会停止 */
	*(buf + 1) = 't';
	/* 打印单个字符 */
	printf("%c\n", *(buf + 2));

	char str1[] = "To be or not to be";
	char str2[40];
	char str3[40];

	/* copy to sized buffer (overflow safe): */
	strncpy1(str2, str1, sizeof(str2));
	puts (str2);

	char* p="how are you ?";
	char name[20]="ABCDEFGHIJKLMNOPQRS";

	strcpy(name,p);   //name改变为"how are you ? OPQRS "     ====>错误！
	strncpy(name,p,sizeof(name));    //name改变为"how are you ?      "       ====>正确！
	puts(p);
	puts(name);
	return 0;
}




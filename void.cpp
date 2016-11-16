/*************************************************************************\
*                  Copyright (C) Michael Kerrisk, 2015.                   *
 *                                                                         *
 * This program is free software. You may use, modify, and redistribute it *
 * under the terms of the GNU General Public License as published by the   *
 * Free Software Foundation, either version 3 or (at your option) any      *
 * later version. This program is distributed without any warranty.  See   *
 * the file COPYING.gpl-v3 for details.                                    *
 \*************************************************************************/

/* Listing 4-3 */

#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>
#include "stdio.h"
#include "stdlib.h"
#include <unistd.h>
#include <string.h>

void void_test(void* pv) {
	char * pc = (char *) pv;
	printf("void test msg=%s\n", pc);
}


/*
 * 指针一般不用取引用
 *     第二：引用可以改变其指向地址的数据，但是不能改变其自身的地址（也就是说别名的地址是不会被改变的，但是别名的值会变）
 *     字符串复制 strcpy(s, "Good News!");
 *     http://stackoverflow.com/questions/2898364/strcpy-vs-memcpy
 * */

int main_void(int argc, char *argv[]) {
	char *buf = new char[1];
	strcpy(buf, "Good News!"); /* 给数组赋字符串 遇到\0就停止 */
	void_test(buf);
	return 0;
}

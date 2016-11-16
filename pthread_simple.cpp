/*
 * pthread.cpp
 *
 *  Created on: 2016年5月22日
 *      Author: John
 */

/*************************************************************************\
*                  Copyright (C) Michael Kerrisk, 2015.                   *
 *                                                                         *
 * This program is free software. You may use, modify, and redistribute it *
 * under the terms of the GNU General Public License as published by the   *
 * Free Software Foundation, either version 3 or (at your option) any      *
 * later version. This program is distributed without any warranty.  See   *
 * the file COPYING.gpl-v3 for details.                                    *
 \*************************************************************************/

/* Listing 29-1 */

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
static void * threadFunc(void *arg) {
	char *s = (char *) arg;

	printf("%s", s);

	return (void *) strlen(s);
}
/*
 * 1、pthread_t结构里面有什么，和fd那样用吗？linux下就是一个 typedef unsigned long int pthread_t;
 * 2、函数指针？只能固定返回值和固定一个参数吗？是的，只能通过结构体或者其他方式 http://blog.csdn.net/easecom/article/details/4508292
 *
 *
 * */
int main_pth(int argc, char *argv[]) {
	pthread_t t1;
	void *res;
	int s;

	char mes[] = "Hello world\n";
	/*创建线程
	 *
	   int pthread_create(pthread_t *thread,
	   	    const pthread_attr_t *attr,
        	void *(*start_routine) (void *),
        	void *arg);
    */
	s = pthread_create(&t1, NULL, threadFunc,(void*)mes );
	if (s != 0){
		printf("err %d\n", __LINE__);
		exit(0) ;
	}

	printf("Thread returned %ld %ld\n", t1,pthread_self());

	/*
	 * 等待线程执行完 返回值也是void*
	*/
	s = pthread_join(t1, &res);
	if (s != 0){
		printf("err %d\n", __LINE__);
		exit(0);
	}
	printf("Thread returned %ld\n", (long) res);

	exit(EXIT_SUCCESS);
}

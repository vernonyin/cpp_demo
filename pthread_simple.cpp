/*
 * pthread.cpp
 *
 *  Created on: 2016��5��22��
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
 * 1��pthread_t�ṹ������ʲô����fd��������linux�¾���һ�� typedef unsigned long int pthread_t;
 * 2������ָ�룿ֻ�̶ܹ�����ֵ�͹̶�һ���������ǵģ�ֻ��ͨ���ṹ�����������ʽ http://blog.csdn.net/easecom/article/details/4508292
 *
 *
 * */
int main_pth(int argc, char *argv[]) {
	pthread_t t1;
	void *res;
	int s;

	char mes[] = "Hello world\n";
	/*�����߳�
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
	 * �ȴ��߳�ִ���� ����ֵҲ��void*
	*/
	s = pthread_join(t1, &res);
	if (s != 0){
		printf("err %d\n", __LINE__);
		exit(0);
	}
	printf("Thread returned %ld\n", (long) res);

	exit(EXIT_SUCCESS);
}

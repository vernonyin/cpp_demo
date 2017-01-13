#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <sys/time.h>

/* 线程同步 */

/* !!! volatile内存值 */
static volatile int glob = 0;
static pthread_mutex_t mtx;// = PTHREAD_MUTEX_INITIALIZER;

static void * threadFunc(void *arg) {
	int loops = *((int *) arg);
	int loc, j, s;

	for (j = 0; j < loops; j++) {
		/* lock影响还是很大的 */
		s = pthread_mutex_lock(&mtx);
		if (s != 0) {
			printf("pthread_mutex_lock");
			exit(0);
		}
		loc = glob;
		loc++;
		glob = loc;

		s = pthread_mutex_unlock(&mtx);
		if (s != 0) {
			printf("pthread_mutex_unlock");
			exit(0);
		}
	}

	return NULL;
}

int main(int argc, char *argv[]) {
	pthread_t t1, t2;
	int loops, s;

	loops = 100000000;
	 struct timeval start, end;
	    gettimeofday( &start, NULL );

	s = pthread_create(&t1, NULL, threadFunc, &loops);
	if (s != 0) {
		printf("pthread_mutex_unlock");
		exit(0);
	}
	s = pthread_create(&t2, NULL, threadFunc, &loops);
	if (s != 0) {
		printf("pthread_mutex_unlock");
		exit(0);
	}

	s = pthread_join(t1, NULL);
	if (s != 0) {
		printf("pthread_mutex_unlock");
		exit(0);
	}
	s = pthread_join(t2, NULL);
	if (s != 0) {
		printf("pthread_mutex_unlock");
		exit(0);
	}

	printf("glob = %d\n", glob);
    gettimeofday( &end, NULL );
    int timeuse = 1000000 * ( end.tv_sec - start.tv_sec ) + end.tv_usec -start.tv_usec;
    printf("time: %d us\n", timeuse);
	exit(EXIT_SUCCESS);
}

/*
 * pthread_barrier_t.cpp
 * 一种同步锁的方式，等待所有线程都ok了然后再同步执行
 *  Created on: 2016年5月22日
 *      Author: John
 */

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
pthread_barrier_t b;

void* task(void* param) {
    int id = (int) param;
    printf("before the barrier %d\n", id);
    pthread_barrier_wait(&b);
    printf("after the barrier %d\n", id);
}
/* barrier 屏障 */
int main_barrier() {
    int nThread = 5;
    int i;

    pthread_t thread[nThread];
    pthread_barrier_init(&b, 0, nThread);
    for (i = 0; i < nThread; i++){
        pthread_create(&thread[i], 0, task, (void*)i);
        usleep(10);
    }
    for (i = 0; i < nThread; i++)
        pthread_join(thread[i], 0);
    pthread_barrier_destroy(&b);
    return 0;
}

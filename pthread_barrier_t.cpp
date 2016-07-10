/*
 * pthread_barrier_t.cpp
 * һ��ͬ�����ķ�ʽ���ȴ������̶߳�ok��Ȼ����ͬ��ִ��
 *  Created on: 2016��5��22��
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
/* barrier ���� */
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

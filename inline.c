/*
测试define/inline/func的差距
 * inline function要extern
 */
#include <unistd.h>
#include <stdio.h>
#include <sys/time.h>
#include "include/util.h"

#define define_swap(a,b) do{ int c=b;b=a;a=c;}while(0)

extern inline void inline_func(int* a, int* b) {
    int c = b;
    b = a;
    a = c;
    int cnt = 0;
    for(int i=0;i<1000;i++){
        cnt += i;
    }
}

void func(int* a, int* b) {
    int c = b;
    b = a;
    a = c;
    int cnt = 0;
    for(int i=0;i<1000;i++){
        cnt += i;
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("%s count ...\n", argv[0]);
        return 0;
    }
    int count = atoi(argv[1]);
    int a = 100, b = 300;
	struct timeval start,end;
	gettimeofday( &start, NULL );
    for (int i = 0; i < count; ++i) {
        define_swap(a, b);
    }
    gettimeofday(&end, NULL);
    printf("define time use %d ms \n", (1000 * (end.tv_sec - start.tv_sec) + end.tv_usec / 1000 - start.tv_usec / 1000));
    for (int i = 0; i < count; ++i) {
          inline_func(&a, &b);
    }
    gettimeofday(&start, NULL);
    printf("inline time use %d ms\n", (1000 * (start.tv_sec - end.tv_sec) + start.tv_usec / 1000 - end.tv_usec / 1000));
    for (int i = 0; i < count; ++i) {
        func(&a, &b);
    }
    gettimeofday(&end, NULL);
    printf("func time use %d ms \n", (1000 * (end.tv_sec - start.tv_sec) + end.tv_usec / 1000 - start.tv_usec / 1000));
    return 0;
}


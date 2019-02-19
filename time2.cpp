//
// Created by yin on 2019-01-21.
//

#include<iostream>
#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>

int main(){
    struct timeval tv;
    gettimeofday(&tv,NULL);
    tm* t= localtime(&tv.tv_sec);
    printf("%d-%02d-%02d %02d:%02d:%02d.%03d \n",
        t->tm_year+1900, t->tm_mon+1, t->tm_mday, t->tm_hour, t->tm_min, t->tm_sec,tv.tv_usec/1000);
    sleep(1);
    gettimeofday(&tv,NULL);
    t= localtime(&tv.tv_sec);
    printf("%d-%02d-%02d %02d:%02d:%02d.%03d \n",
           t->tm_year+1900, t->tm_mon+1, t->tm_mday, t->tm_hour, t->tm_min, t->tm_sec,tv.tv_usec/1000);
    sleep(1);
    gettimeofday(&tv,NULL);
    t= localtime(&tv.tv_sec);
    printf("%d-%02d-%02d %02d:%02d:%02d.%03d \n",
           t->tm_year+1900, t->tm_mon+1, t->tm_mday, t->tm_hour, t->tm_min, t->tm_sec,tv.tv_usec/1000);
    sleep(1);
    gettimeofday(&tv,NULL);
    t= localtime(&tv.tv_sec);
    printf("%d-%02d-%02d %02d:%02d:%02d.%03d \n",
           t->tm_year+1900, t->tm_mon+1, t->tm_mday, t->tm_hour, t->tm_min, t->tm_sec,tv.tv_usec/1000);
    sleep(1);
    gettimeofday(&tv,NULL);
    t= localtime(&tv.tv_sec);
    printf("%d-%02d-%02d %02d:%02d:%02d.%03d \n",
           t->tm_year+1900, t->tm_mon+1, t->tm_mday, t->tm_hour, t->tm_min, t->tm_sec,tv.tv_usec/1000);
    sleep(1);
    gettimeofday(&tv,NULL);
    t= localtime(&tv.tv_sec);
    printf("%d-%02d-%02d %02d:%02d:%02d.%03d \n",
           t->tm_year+1900, t->tm_mon+1, t->tm_mday, t->tm_hour, t->tm_min, t->tm_sec,tv.tv_usec/1000);


    struct timeval tv1,tv2;
    gettimeofday(&tv1,NULL);
    for(int i=0;i<1000000;i++){
        gettimeofday(&tv2,NULL);
    }
    gettimeofday(&tv2,NULL);
    printf("microsecond:%ld\n",tv2.tv_sec*1000 + tv2.tv_usec/1000-
            tv1.tv_sec*1000 + tv1.tv_usec/1000);  //微秒

    time_t now = time(0);

//    struct timeval tv1,tv2;
//    gettimeofday(&tv1,NULL);
//    for(int i=0;i<1000000;i++){
//        now = time(0);
//    }
//    gettimeofday(&tv2,NULL);
//    printf("microsecond:%ld\n",tv2.tv_sec*1000 + tv2.tv_usec/1000-
//                               tv1.tv_sec*1000 + tv1.tv_usec/1000);  //微秒
//    sleep(3); // 为方便观看，让程序睡三秒后对比
//    std::cout << "3s later:" << std::endl;
//
//    gettimeofday(&tv,NULL);
//    printf("second:%ld\n",tv.tv_sec);  //秒
//    printf("millisecond:%ld\n",tv.tv_sec*1000 + tv.tv_usec/1000);  //毫秒
//    printf("microsecond:%ld\n",tv.tv_sec*1000000 + tv.tv_usec);  //微秒
    return 0;
}
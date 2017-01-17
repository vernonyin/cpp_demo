/*
测试原子++操作和非原子++操作
*/
#include <thread>
#include <atomic>
#include <unistd.h>
#include <stdio.h>
#include <list>
#include <vector>
 #include <sys/time.h>
//原子++
std::atomic_int iCount(0);
//非原子性++
int iCnt;
const int COUNT = 90000000;
const int THREAD_NUM = 20;
/**
非原子加多线程下最后的结果不确定！！！
iCnt=4853200...
iCnt=9889662...
iCnt=10000000...
iCnt=10000000...
*/
void threadfun1(int k)
{
    for(int i=0;i<COUNT;i++){
		iCnt++;
	}
}

void threadfun_atomic(int k)
{
    for(int i=0;i<COUNT;i++){
		iCount++;
	}
}
int main()
{
    std::atomic_bool b;
    std::vector<std::thread> lstThread;
	struct timeval start,end;
	gettimeofday( &start, NULL );
    for (int i = 0; i < THREAD_NUM; ++i)
    {
        lstThread.push_back(std::thread(threadfun1,i));
//		lstThread[i].detach();
    }
	for (int i = 0; i < THREAD_NUM; ++i)
    {
		lstThread[i].join();
	}
	gettimeofday( &end, NULL );
	printf("normal time use %d ms \n",(1000 * ( end.tv_sec - start.tv_sec ) + end.tv_usec/1000 -start.tv_usec/1000));
	printf("count=%d\n",iCnt);
    std::vector<std::thread> lstAtomicThread;
	for (int i = 0; i < THREAD_NUM; ++i)
    {
        lstAtomicThread.push_back(std::thread(threadfun_atomic,i));
		//自己释放内存
		//http://www.cnblogs.com/bits/archive/2009/12/04/no_join_or_detach_memory_leak.html
//		th1.detach();
		//等待结束		th1.join();
    }
	for (int i = 0; i < THREAD_NUM; ++i)
    {
        lstAtomicThread[i].join();
    }
 	gettimeofday( &start, NULL );
    printf("atomic time use %d ms\n",(1000 * ( start.tv_sec - end.tv_sec ) + start.tv_usec/1000 -end.tv_usec/1000));

//	usleep(1000000);
	printf("iCnt=%d,iCount=%d \n",iCnt,(int)iCount);
	return 0;
}


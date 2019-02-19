//
// Created by yin on 2019-01-22.
//

//hash_shm.h

/*
一个锯齿数组，每一行都是素数，从多到少
* * * * * *
* * * * *
* * * *
* * *
* *
*
*/

#ifndef _STORMLI_HASH_SHM_H_
#define _STORMLI_HASH_SHM_H_

#include<iostream>
#include<cstdlib>
#include<cmath>
#include<string.h>
//#include<sys/shm.h>
using namespace std;

template<typename valueType,unsigned long maxLine,int lines>
class hash_shm
{
public:
    int find(unsigned long _key);    //if _key in the table,return 0,and set lastFound the position,otherwise return -1
    int remove(unsigned long _key);    //if _key not in the table,return-1,else remove the node,set the node key 0 and return 0

    //insert node into the table,if the _key exists,return 1,if insert success,return 0;and if fail return -1
    int insert(unsigned long _key,const valueType &_value);
    void clear();        //remove all the data

public:    //some statistic function
    double getFullRate()const;        //the rate of the space used

public:
    //constructor,with the share memory start position and the space size,if the space is not enough,the program will exit
    hash_shm(void *startShm,unsigned long shmSize=sizeof(hash_node)*maxLine*lines);

    //constructor,with the share memory key,it will get share memory,if fail,exit
    //hash_shm(key_t shm_key);
    ~hash_shm(){}    //destroy the class

    void foreach(void (*fn)(unsigned long _key,valueType &_value));
private:
    void *mem;        //the start position of the share memory  // the mem+memSize  space used to storage the runtime data:currentSize
    unsigned long memSize;    //the size of the share memory
    unsigned long modTable[lines];    //modtable,the largest primes, hash表的阶，为每一阶产生一个素数
    unsigned long modTotal[lines];    //modTotal[i] is the summary of the modTable
    unsigned long maxSize;        //the size of the table
    unsigned long *currentSize;    //current size of the table ,the pointer of the shm mem+memSize
    void *lastFound;        //write by the find function,record the last find place

    struct hash_node{        //the node of the hash table
        unsigned long key;    //when key==0,the node is empty
        valueType value;    //name-value pair
    };



private:
    //bool getShm(key_t shm_key);    //get share memory,used by the constructor
    void getMode();        //get the largest primes blow maxLine,use by the constructor
    void *getPos(unsigned int _row,unsigned long _col);//get the positon with the (row,col)
};

template<typename vT,unsigned long maxLine,int lines>
hash_shm<vT,maxLine,lines>::hash_shm(void *startShm,unsigned long shmSize)
{
    if(startShm!=NULL){
        cerr<<"Argument error\n Please check the shm address\n";
        exit(-1);
    }
    getMode();
    maxSize=0;
    int i;
    for(i=0;i<lines;i++)    //count the maxSize
    {
        maxSize+=modTable[i];  //HASH存储的元素个数，就是把每一阶的元素个数加起来
        if(i!=0)modTotal[i]=modTotal[i-1]+modTable[i-1];
        else modTotal[i]=0;    //caculate the modTotal
    }
    if(shmSize<sizeof(hash_node)*(maxSize+1)){    //check the share memory size
        cerr<<"Not enough share memory space\n";
        exit(-1);
    }
    memSize=shmSize;
    if(*(currentSize=(unsigned long *)((long)mem+memSize))<0)
        *currentSize=0;;
}

/*
template<typename vT,unsigned long maxLine,int lines>
hash_shm<vT,maxLine,lines>::hash_shm(key_t shm_key)
{    //constructor with get share memory
    getMode();
    maxSize=0;
    for(int i=0;i<lines;i++)
	{
        maxSize+=modTable[i];
		if(i!=0)modTotal[i]=modTotal[i-1]+modTable[i-1];
        else modTotal[i]=0;
	}
    memSize=sizeof(hash_node)*maxSize;
    if(!getShm(shm_key)){
        exit(-1);
    }
//    memset(mem,0,memSize);
    if(*(currentSize=(unsigned long *)((long)mem+memSize))<0)
        *currentSize=0;

}
*/


template<typename vT,unsigned long maxLine,int lines>
int hash_shm<vT,maxLine,lines>::find(unsigned long _key)
{
    unsigned long hash;
    hash_node *pH=NULL;
    for(int i=0;i<lines;i++)  //查找元素的时候，在每一阶上去查找
    {
        hash=(_key+maxLine)%modTable[i];    //calculate the col position,  key加上最大的元素个数，可以避免key太小
        //以上计算得到列
        pH=(hash_node *)getPos(i,hash);
//        if(pH==NULL)return -2;    //almost not need
        if(pH->key==_key){
            lastFound=pH;
            return 0;
        }
        //如果hash冲突，继续在下一阶查找
    }
    return -1;
}

/// 删除一个元素，仅仅标记这个节点的key为0即可
template<typename vT,unsigned long maxLine,int lines>
int hash_shm<vT,maxLine,lines>::remove(unsigned long _key)
{
    if(find(_key)==-1)return -1;    //not found
    hash_node *pH=(hash_node *)lastFound;
    pH->key=0;        //only set the key 0
    (*currentSize)--;
    return 0;
}

template<typename vT,unsigned long maxLine,int lines>
int hash_shm<vT,maxLine,lines>::insert(unsigned long _key,const vT &_value)
{
    if(find(_key)==0)return 1;    //if the key exists
    unsigned long hash;
    hash_node *pH=NULL;
    for(int i=0;i<lines;i++)
    {
        hash=(_key+maxLine)%modTable[i];
        pH=(hash_node *)getPos(i,hash);
        if(pH->key==0){        //find the insert position,insert the value
            pH->key=_key;
            pH->value=_value;
            (*currentSize)++;
            return 0;
        }
    }
    return -1;    //all the appropriate position filled
}


template<typename vT,unsigned long maxLine,int lines>
void hash_shm<vT,maxLine,lines>::clear()
{
    memset(mem,0,memSize);
    *currentSize=0;
}

/*
template<typename vT,unsigned long maxLine,int lines>
bool hash_shm<vT,maxLine,lines>::getShm(key_t shm_key)
{
    int shm_id=shmget(shm_key,memSize,0666);
    if(shm_id==-1)    //check if the shm exists
    {
        shm_id=shmget(shm_key,memSize,0666|IPC_CREAT);//create the shm
        if(shm_id==-1){
            cerr<<"Share memory get failed\n";
            return false;
        }
    }
    mem=shmat(shm_id,NULL,0);    //mount the shm
    if(int(mem)==-1){
        cerr<<"shmat system call failed\n";
        return false;
    }
    return true;
}
*/

/// vT value的数据类型
/// maxLine 每阶的最大元素个数
/// lines hash的阶
/// 为每一阶产生一个素数
/// 素数从大到小的排列
template<typename vT,unsigned long maxLine,int lines>
void hash_shm<vT,maxLine,lines>::getMode()
{        //采用 6n+1 6n-1 素数集中原理
    // 每阶至少5个元素
    if(maxLine<5){exit(-1);}

    unsigned long t,m,n,p;
    int i,j,a,b,k;
    int z=0;

    // 1000/6 = 166
    // 找166到0之间的所有素数吗？
    for(t=maxLine/6;t>=0,z<lines;t--)  //逗号是什么意思？or吗
    {
        i=1;j=1; k=t%10;
        m=6*t;                                        /**i,j的值 是是否进行验证的标志也是对应的6t-1和6t+1的素性标志**/
        if(((k-4)==0)||((k-9)==0)||((m+1)%3==0))j=0;/*此处是简单验证6*t-1,6*t+1 是不是素数，借以提高素数纯度**/
        if(((k-6)==0)||((m-1)%3==0))i=0;            /***先通过初步判断去除末尾是5，及被3整除的数***/
        for(p=1;p*6<=sqrt(m+1)+2;p++ )
        {
            n=p*6;                                    /**将6*p-1和6*p+1看作伪素数来试除*****/
            k=p%10;
            a=1;b=1;                                /**同样此处a,b的值也是用来判断除数是否为素数提高除数的素数纯度**/
            if(((k-4)==0)||((k-9)==0))a=0;
            if(((k-6)==0))b=0;
            if(i){                            /*如果i非零就对m-1即所谓6*t-1进行验证，当然还要看除数n+1,n-1,素性纯度*/
                if(a){if((m-1)%(n+1)==0)i=0;}        /***一旦被整除就说明不是素数故素性为零即将i 赋值为零***/
                if(b){if((m-1)%(n-1)==0)i=0;}
            }
            if(j){                           /**如果j非零就对m+1即所谓6*t+1进行验证，当然还要看除数n+1,n-1,素性纯度*/
                if(a){if((m+1)%(n+1)==0)j=0;}         /***一旦被整除就说明不是素数故素性为零即将j 赋值为零***/
                if(b){if((m+1)%(n-1)==0)j=0;}
            }
            if((i+j)==0)break;                     /**如果已经知道6*t-1,6*t+1都不是素数了那就结束试除循环***/
        }
        if(j){modTable[z++]=m+1;if(z>= lines)return;}
        if(i){modTable[z++]=m-1;if(z>= lines)return;}
    }
}

template<typename vT,unsigned long maxLine,int lines>
void *hash_shm<vT,maxLine,lines>::getPos(unsigned int _row,unsigned long _col)
{
    //unsigned long pos=0UL;
    //for(int i=0;i<_row;i++)    //calculate the positon from the start
    //    pos+=modTable[i];
    //pos+=_col;
    unsigned long pos=_col+modTotal[_row];

    if(pos>=maxSize)return NULL;
    return (void *)((long)mem+pos*sizeof(hash_node));
}

/// 占用百分比
template<typename vT,unsigned long maxLine,int lines>
double hash_shm<vT,maxLine,lines>::getFullRate()const
{
    return double(*currentSize)/maxSize;
}

template<typename vT,unsigned long maxLine,int lines>
void hash_shm<vT,maxLine,lines>::foreach(void (*fn)(unsigned long _key,vT &_value))
{
    typedef  unsigned long u_long;
    u_long beg=(u_long)mem;
    u_long end=(u_long)mem+sizeof(hash_node)*(modTable[lines-1]+modTotal[lines-1]);
    hash_node *p=NULL;
    for(u_long pos=beg;pos<end;pos+=sizeof(hash_node))
    {
        p=(hash_node *)pos;
        if(p->key!=0)fn(p->key,p->value);
    }
}

#endif

/*
g++ -o hash_shm_1.h.gch -x c++-header -c hash_shm_1.h -g
*/
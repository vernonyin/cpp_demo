#include <iostream>
using namespace std;

int main(){
/*
https://www.nowcoder.com/profile/7400356/test/15296408/44552#summary
int (*p)[3];
这里首先确定：p是一个指针，一个指向数组的指针。
p = &(p[0])       p是二维指针
p[0] = &(p[0][0]) p[0]是一维指针

p[0] + 1表示在列上移动。  e.g:  p[0] + 1 = &p[0][0] + 1 = &p[0][1]
p + 1   表示在行上移动。  e.g: p + 1 = &(p[0]) + 1 = &p[1]
*/
    int n[][3] = {10,20,30,40,50,60};
    int (*p)[3];
    p=n;
	printf("p[0]=%p\n",p);
	printf("p[0]=%p\n",p[0]);
	printf("p[1]=%p\n",p[1]);
	printf("p[2]=%p\n",p[2]);
    cout<<p[0][0]<<","<<*(p[0]+1)<<","<<(*p)[2]<<endl;
    cout<<p[0][0]<<","<<*(*p+1)<<","<<(*p)[2]<<endl;
	return 0;	
}

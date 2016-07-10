#include <vector>
#include <map>
#include <string>
#include <exception>
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <cstdint>
#include <unistd.h>

using namespace std;

struct st {
	vector<int> a;
	string s;
};
int main_test3() {
	/* sizeof是指针大小  */
	cout << "size=" << sizeof(struct st) << endl;
	cout << "size=" << sizeof(string) << endl;
	int a=10;
	int b=a++;
	cout<<"b="<<b<<endl;
	a=10;
	b=++a;
	cout<<"b="<<b<<endl;
	bool bl=9999;
	cout<<"sizeof(bool)="<<sizeof(bool)<<endl;
	cout<<"sizeof(bl)="<<sizeof(bl)<<endl;
	cout<<"sizeof(char)="<<sizeof(char)<<endl;

	float fnum = 4.5;
	float *pf = &fnum;
	cout<<"sizeof(float *)="<<sizeof(pf)<<endl;
	cout << "sizeof(int)=" << sizeof(int) << endl;
	cout << "sizeof(long)=" << sizeof(long) << endl;
	cout << "sizeof(long int)=" << sizeof(long int) << endl;
	cout << "sizeof(long long)=" << sizeof(long long ) << endl;
	cout << "sizeof(long long int)=" << sizeof(long long int) << endl;
	cout << "sizeof(int32_t)=" << sizeof(int32_t) << endl;
}

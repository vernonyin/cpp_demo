#include <iostream>
#include <stdio.h>
using namespace std;
int add(int a) {
	return a;
}
void func_point() {

	//类型强转
//  sppdll.spp_handle_init = (spp_handle_init_t)dlsym(handle, "spp_handle_init");
	int (*pf)(int); //定义一个函数指针
	typedef int (Add)(int); //定义一种类型，指针也可以不用
	Add* handle = &add;
	pf = &add; //指针初始化
	cout << pf(10); //调用1
	cout << handle(10); //调用2
}

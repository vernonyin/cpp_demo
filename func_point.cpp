#include <iostream>
#include <stdio.h>
using namespace std;
int add(int a) {
	return a;
}
void func_point() {

	//����ǿת
//  sppdll.spp_handle_init = (spp_handle_init_t)dlsym(handle, "spp_handle_init");
	int (*pf)(int); //����һ������ָ��
	typedef int (Add)(int); //����һ�����ͣ�ָ��Ҳ���Բ���
	Add* handle = &add;
	pf = &add; //ָ���ʼ��
	cout << pf(10); //����1
	cout << handle(10); //����2
}

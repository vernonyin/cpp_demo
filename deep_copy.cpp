#include<iostream>
using namespace std;
class A{
public:
	A():m_ptr(new int(0)){
		cnt++;
		cout<<"construct"<<endl;
	}

	A(const A& a):m_ptr(new int(*a.m_ptr)){
		cnt++;
		cout<<"copy construct"<<endl;
	}
	~A(){
		cout<<"destruct.cnt=="<<cnt<<endl;
		delete m_ptr;
	}
	void print(){
		cout<<num<<"...print..."<<endl;
	}
	A& operator=(const A& a){
		m_ptr = a.m_ptr;
		cnt++;
		cout<<"operator construct"<<endl;
		return *this;
	}
	int num;
	static int cnt;
private:
	int* m_ptr;

};

/* ��̬��Ա��ʼ������Ȼ��Ҫ�������� */
int A::cnt = 0;

A get(){
	A b;
	b.num=999;
	return b;
}

int main_deep(){
	/*todo ���ﻹ��û�и㶮����������ֵ�Ƿ�Ҫ���¸�ֵ�Ǻ͵��÷�ʽ�йأ�����˵�Ż������Ż��ˡ� */
	A a=get();
	A b=a; // �ȼ���  === b(a)
	/*todo ��������͹��캯��������3�Σ�������������ֻ������2�� */
	b = a;

//
//	A b;
//	get();
//	a.print();
//	A item;
//	/* ����copy���캯�� */
//	decltype(item) itemB ;
//	itemB = item;/* ��ֵ���캯�� */
//
//	/* �������캯�� */
//	auto itemC = item;
//	auto itemD(item);

}

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

/* 静态成员初始化，居然还要加上类型 */
int A::cnt = 0;

A get(){
	A b;
	b.num=999;
	return b;
}

int main_deep(){
	/*todo 这里还是没有搞懂，函数返回值是否要重新赋值是和调用方式有关？还是说优化器给优化了。 */
	A a=get();
	A b=a; // 等价于  === b(a)
	/*todo 如果这样就构造函数调用了3次，但是析构函数只调用了2次 */
	b = a;

//
//	A b;
//	get();
//	a.print();
//	A item;
//	/* 调用copy构造函数 */
//	decltype(item) itemB ;
//	itemB = item;/* 赋值构造函数 */
//
//	/* 拷贝构造函数 */
//	auto itemC = item;
//	auto itemD(item);

}

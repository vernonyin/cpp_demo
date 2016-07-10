#include <map>
#include <iostream>
using namespace std;
#include <functional>

using namespace std::placeholders;

int f1(int a){
	return a;
}

int main_nal(int argc, char *argv[]) {

	/* 就等同于函数指针 */
	function<int(int)> f_display = f1;
	cout<<f_display(1)<<endl;

	/* 怎么使用？ */
	function<int(int)> f = bind(f1,_1);
	cout<<f(1)<<endl;

	/* lamba表达式:stl函数 */
	auto x1 = [](int i){return i;};
	cout<<x1(1)<<endl;
	return 0;
}


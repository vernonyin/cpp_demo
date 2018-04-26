#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> Vec;
typedef vector<int>::iterator VecIt;

void print(Vec &v)
{
	VecIt it;
	for(it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}

	cout << endl;
}

void deleteValueFromVector(Vec &v, int n = 5)
{
	VecIt it;
	VecIt it2=v.begin();
	for(it = v.begin(); it != v.end(); )
	{
		if(0 == *it % n)
		{
			v.erase(it);
		}
		else
			it++;
	}
	for(it = it2; it != v.end(); it++)
	{
	printf("%d ,",*it);
	}
}

int main()
{
	Vec v;
	int i = 0;
	for(i = 0; i < 21; i++)
	{
		v.push_back(i); // 不能再傻傻地用下标了
	}

	print(v);

	deleteValueFromVector(v,5); // 程序崩溃
	print(v);

	return 0;
}


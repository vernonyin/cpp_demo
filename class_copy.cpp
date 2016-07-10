#include <iostream>
#include <cstring>
using namespace std;

class ClassTest {
public:
	ClassTest() {
		c[0] = '\0';
		cout << "ClassTest()" << endl;
	}
	ClassTest& operator=(const ClassTest &ct) {
		strcpy(c, ct.c);
		cout << "ClassTest& operator=(const ClassTest &ct)" << endl;
		return *this;
	}
	ClassTest(const char *pc) {
		strcpy(c, pc);
		cout << "ClassTest (const char *pc)" << endl;
	}
// private:
	ClassTest(const ClassTest& ct) {
		strcpy(c, ct.c);
		cout << "ClassTest(const ClassTest& ct)" << endl;
	}
private:
	char c[256];
};

int main_test() {
	cout << "ct1: ";
	ClassTest ct1("ab"); //ֱ�ӳ�ʼ��
	cout << "ct2: ";
	ClassTest ct2 = "ab"; //���Ƴ�ʼ��
	cout << "ct3: ";
	ClassTest ct3 = ct1; //���Ƴ�ʼ��
	cout << "ct4: ";
	ClassTest ct4(ct1); //ֱ�ӳ�ʼ��
	cout << "ct5: ";
	ClassTest ct5 = ClassTest(); //���Ƴ�ʼ��
	return 0;
}

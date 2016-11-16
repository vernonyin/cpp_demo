/*
 * share_ptr.cpp
 *
 *  Created on: 2016年6月2日
 *      Author: John
 */
#include <iostream>
#include <memory>
using namespace std;

class Investment{

};

Investment* createInvestment(){
	return new Investment();
}

void f(){
	Investment* pInv = createInvestment();
	delete pInv;
}

int main_share(){
	f();

	auto_ptr<Investment> pInv(createInvestment());
	cout<<"end...."<<endl;
}




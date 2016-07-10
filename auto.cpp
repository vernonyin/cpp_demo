/*
 * auto.cpp
 *
 *  Created on: 2016Äê6ÔÂ3ÈÕ
 *      Author: John
 */
#include <map>
#include <iostream>
using namespace std;

int main_auto(int argc, char *argv[]) {
	map<int, int> mi = { { 1, 1 }, { 2, 3 } };
	for (auto it = mi.begin(); it != mi.end(); it++) {
		cout << "first:" << it->first << ",end" << it->second << endl;
	}

	for(auto it : mi){
		cout << "first:" << it.first << ",end" << it.second << endl;
	}
	return 0;
}


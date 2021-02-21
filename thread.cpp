//
// Created by yin on 2018/12/3.
//

#include <iostream>
#include <utility>
#include <vector>
#include <string>
#include <thread>
#include <mutex>

using namespace std;


int main() {
  //线程独享的
//  thread_local int x = 10;
   int x = 10;
  static once_flag flag;
  auto f = [&](int n) {
      call_once(flag, []() {
          cout << "call function f" << endl;
      });

      for(int i = 0; i<999999999; i++){
        x += n;
      }


      cout << "x=" << x << endl;
  };

  thread t1(f, 10);

  thread t2(f, 20);
//  usleep(100);

  while (1);;
  return 0;
}
//
// Created by yin on 2018/12/3.
//

#include <iostream>
#include <utility>
#include <vector>
#include <string>
#include <thread>
#include <mutex>
#include "include/json.hpp"

using namespace std;

using json=nlohmann::json;

int main() {
  json j;

  j["a"] = 1;
  cout<<"hello world"<<endl;
  cout<<j.dump()<<endl;
  return 0;
}
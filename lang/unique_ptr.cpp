//
// Created by yin on 2019-01-26.
//

#include <iostream>
#include <memory>

using namespace std;

int main() {
#if 0
  auto ptr = std::make_unique<int>(5);
  cout << "ptr = " << *ptr << endl;
  *ptr = 10;
  auto ptr2 = move(ptr);

  cout << "ptr = " << *ptr << endl;
  cout << "ptr2 = " << *ptr2 << endl;
#endif
  auto sptr = make_shared<int>(5);
  cout << "ptr = " << *sptr << endl;
  *sptr = 10;
  auto ptr2 = sptr;

  *sptr = 14;
  cout << "ptr = " << *sptr << endl;
  cout << "ptr2 = " << *ptr2 << endl;
  return 0;
}
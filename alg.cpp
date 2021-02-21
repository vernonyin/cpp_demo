//
// Created by yin on 2018/12/3.
//

#include <iostream>
#include <utility>
#include <vector>
#include <string>

using namespace std;




int main()
{
  vector<int> vc = {1,2,3,4,5,6,7,8};

  auto n = count(vc.begin(),vc.end(),3);
  cout<<"count = "<<n<<endl;

  //计数
  auto n2 = count_if(vc.begin(),vc.end(),[](int x){
    return x%2;
  });
  cout<<"count2 = "<<n2<<endl;

  for_each(begin(vc),end(vc),[](int x){
    x++;
  });

  for_each(begin(vc),end(vc),[](int x){
     cout<<"x="<<x<<endl;
  });

  auto mm = minmax_element(begin(vc),end(vc));

  cout<<"min="<<*mm.first<<endl;
  cout<<"max="<<*mm.second<<endl;


  return 0;
}
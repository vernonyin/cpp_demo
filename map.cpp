//
// Created by yin on 2019-01-21.
//

#include <map>
#include <iostream>
using namespace std;

int main(){
    map<int,int> m;
    for(int i=1;i<100;i++){
        m[i]=i;
    }
    for(  std::map<int,int>::iterator it=m.begin();it!=m.end();it++){
        if (it->first %10 == 0){
            m.erase(it);
        }
    }

    for(auto kv:m){
        cout<<kv.first<<","<<kv.second<<endl;
    }
    return 0;
}
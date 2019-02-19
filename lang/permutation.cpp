//
// Created by yin on 2019-02-14.
//

#include<iostream>
#include<algorithm>
#include <vector>
#include <set>

using namespace std;

int main(){
    string str="ABCD";
    vector<char> chars={'A','B','C','D','E','F'};
    cout<<chars[0]<<chars[1]<<"  "<<chars[2]<<chars[3]<<endl;
    int i=0;
    vector<vector<string>> res;
    while(next_permutation(chars.begin(),chars.end())){
        cout<<chars[0]<<chars[1]<<"  "<<chars[2]<<chars[3]<<endl;
        vector<string> v1;
        string s;
        if(chars[0] > chars[1]){
            s.push_back(chars[1]);
            s.push_back(chars[0]);
        }else{
            s.push_back(chars[0]);
            s.push_back(chars[1]);
        }

        v1.push_back(s);
        s = "";
        if(chars[2] > chars[3]){
            s.push_back(chars[3]);
            s.push_back(chars[2]);
        }else{
            s.push_back(chars[2]);
            s.push_back(chars[3]);
        }
        v1.push_back(s);

        s = "";
        if(chars[4] > chars[5]){
            s.push_back(chars[5]);
            s.push_back(chars[4]);
        }else{
            s.push_back(chars[4]);
            s.push_back(chars[5]);
        }
        v1.push_back(s);

        res.push_back(v1);
    }

    set<string> st;
    int ii=1;
    vector<string> res1;
    for(auto r:res){
        sort(r.begin(),r.end());
        string key="";
        for(auto b : r){
            key+=b;
        }
        if(st.find(key) != st.end()){
            continue;
        }
        st.insert(key);

        cout<<ii++<<"  ";
        string tmp;
        for(auto b : r){
            cout<< b;
            tmp+=b;
        }
        res1.push_back(tmp);
        cout<<endl;
    }

    vector<string> res2;
    sort(res1.begin(),res2.end());
    for(auto b : res1){
        cout<< b<<endl;
    }

    return 0;
}
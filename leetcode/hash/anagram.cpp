//
// Created by yin on 2019-02-19.
//
#include <unordered_map>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> hash;
        for(int i=0;i<s.size();i++){
            hash[s[i]]++;
        }
        for(int i=0;i<t.size();i++){
            hash[t[i]]--;
        }
        for(auto it:hash){
            if(it.second != 0){
                return false;
            }
        }
        return true;
    }
};

int main(){
    Solution s;
    cout<<s.isAnagram("a","b")<<endl;
    return 0;
}

//
// Created by yin on 2019-02-19.
//
#include <stack>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i=0;i<s.size();i++){
            if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
                st.push(s[i]);
            }else{
                if(st.size() == 0){
                    return false;
                }
                char top = st.top();
                if(s[i] == ')' && top != '('){
                    return false;
                }else if (s[i] == ']' && top != '['){
                    return false;
                }
                else if (s[i] == '}' && top != '{'){
                    return false;
                }
                st.pop();
            }
        }
        if(st.size()){
            return false;
        }
        return true;
    }
};

int main(){
    std::stack<int> mystack;
    cout<<"top "<<mystack.top();
//    mystack.pop();
    Solution s;
    string ss("{");
    s.isValid(ss);
    return 0;
}
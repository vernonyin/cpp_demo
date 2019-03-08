//
// Created by yin on 2019-02-24.
//
#include <iostream>
#include <queue>
using  namespace std;

class Solution {
public:
    void Insert(int num)
    {
        if(q1.size() >0 && num > q1.top())
            q2.push(num);
        else
            q1.push(num);

        if(q2.size() == q1.size()+2){
            int tmp = q2.top();
            q2.pop();
            q1.push(tmp);
        }
        if(q1.size() == q2.size() +2){
            int tmp = q1.top();
            q1.pop();
            q2.push(tmp);
        }
    }

    double GetMedian()
    {
        if(q1.size() == q2.size()){
            return (double)(q1.top() + q2.top()) /2;
        }else if (q1.size() > q2.size()){
            return q1.top();
        }else{
            return q2.top();
        }
    }

    priority_queue<int> q1;
    priority_queue<int,vector<int>,greater<int>> q2;
};


int main(){
    priority_queue<int> q1;
    priority_queue<int> q2;
    q1.push(1);
    if(q1.size() - q2.size() >1){
        cout<<"q1 < q2"<<endl;
    }
    auto q1s = q1.size();
    auto q2s = q2.size();
    auto s = ((int)q2.size() - (int)q1.size()) >1;
    if(auto s = (q2.size() - q1.size()) >1){
        cout<<"q2 < q1"<<endl;
    }
    vector<int> input = {5,2,3,4,1,6,7,0,8};
//    Solution s;
//    for(auto i :input){
//        s.Insert(i);
//        cout<<s.GetMedian()<<endl;
//    }
}
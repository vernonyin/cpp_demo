//
// Created by yin on 2019-02-18.
//

#include <iostream>
#include <algorithm>    // std::make_heap, std::pop_heap, std::push_heap, std::sort_heap
#include <vector>       // std::vector
#include <queue>

using namespace std;
//优先队列，底层是完全二叉树
//https://leetcode.com/problems/find-median-from-data-stream/submissions/

int main() {


    int input=2;
    priority_queue<int, std::vector<int>,std::greater<int>> MaxHeap;
    priority_queue<int> MinHeap;

    vector<int> vint;

    while (input) {
        cin >> input;
        vint.push_back(input);

        if (MinHeap.size() > 0 && input <= MinHeap.top()) {
            MinHeap.push(input);
        } else {
            MaxHeap.push(input);
        }

        int min_size =  MinHeap.size();
        int max_size = MaxHeap.size();
        if (min_size - max_size > 1) {
            int tmp = MinHeap.top();
            MinHeap.pop();
            MaxHeap.push(tmp);
        }else if (max_size - min_size > 1) {
            int tmp = MaxHeap.top();
            MaxHeap.pop();
            MinHeap.push(tmp);
        }

        sort(vint.begin(),vint.end());
        for(auto i:vint){
            cout<<i<<" ";
        }
        cout<<endl;
        if (MaxHeap.size() == MinHeap.size()) {
            cout << MaxHeap.top() << "+" << MinHeap.top() << endl;
        } else if (MaxHeap.size() > MinHeap.size()) {
            cout << MaxHeap.top() << endl;
        } else {
            cout << MinHeap.top() << endl;
        }

    }


}
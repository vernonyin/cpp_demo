//
// Created by yin on 2019-02-18.
//

#include <iostream>
#include <algorithm>    // std::make_heap, std::pop_heap, std::push_heap, std::sort_heap
#include <vector>       // std::vector

using namespace std;

int getMid() {

}

int main() {
//    vector<int> Heap={1,26,57,3,7,85};
//    cout<<"make_heap"<<endl;
//    make_heap(Heap.begin(),Heap.end());
//    for(int i:Heap){
//        cout<<i<<",";
//    }


    int input=2;
    vector<int> MaxHeap, MinHeap;

    vector<int> vint;

    while (input) {
        cin >> input;
        vint.push_back(input);

        if (MinHeap.size() > 0 && input <= MinHeap[0]) {
            MinHeap.push_back(input);
            push_heap(MinHeap.begin(), MinHeap.end());
        } else {
            MaxHeap.push_back(input);
            push_heap(MaxHeap.begin(), MaxHeap.end(), greater<int>());
        }
        int min_size =  MinHeap.size();
        int max_size = MaxHeap.size();
        if (min_size - max_size > 1) {
            pop_heap(MinHeap.begin(), MinHeap.end());
            int tmp = MinHeap.back();
            MinHeap.pop_back();
            MaxHeap.push_back(tmp);
        }else if (max_size - min_size > 1) {
            pop_heap(MaxHeap.begin(), MaxHeap.end());
            int tmp = MaxHeap.back();
            MaxHeap.pop_back();
            MinHeap.push_back(tmp);
        }

        make_heap(MaxHeap.begin(), MaxHeap.end(), greater<int>());
        make_heap(MinHeap.begin(), MinHeap.end());

        sort(vint.begin(),vint.end());
        for(auto i:vint){
            cout<<i<<" ";
        }
        cout<<endl;
        if (MaxHeap.size() == MinHeap.size()) {
            cout << MaxHeap[0] << "+" << MinHeap[0] << endl;
        } else if (MaxHeap.size() > MinHeap.size()) {
            cout << MaxHeap[0] << endl;
        } else {
            cout << MinHeap[0] << endl;
        }

    }


}
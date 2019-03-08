//
// Created by yin on 2019-02-25.
//
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:

    bool VerifySquenceOfBST1(vector<int> sequence) {
        if(sequence.size() == 0) return false;
        return _verify(sequence,0,sequence.size());
    }

    bool _verify1(vector<int> sequence,int l,int r){
        if(l >= r) return true;

        int mid = sequence[r-1];
        int pos = l;
        for(;pos < r-1 ;pos++){
            if(sequence[pos] > mid){
                break;
            }
        }

        for(int j=pos;j<r-1 ;j++){
            if(sequence[j] < mid){
                return false;
            }
        }
        bool left = true;
        if(pos > 0){
            left = _verify(sequence,l,pos);
        }
        bool right = true;
        if(pos< r-1){
            right = _verify(sequence,pos,r-2);
        }
        return left && right;
    }

    bool VerifySquenceOfBST(vector<int> sequence) {
        return _verify(sequence,0,sequence.size()-1);
    }

    bool _verify(vector<int> sequence,int l,int r){
        if(l >= r) return true;

        int mid = sequence[r];
        int pos = l;
        for(;pos < r ;pos++){
            if(sequence[pos] > mid){
                break;
            }
        }

        for(int j=pos;j<r ;j++){
            if(sequence[j] < mid){
                return false;
            }
        }
        bool left = true;
        if(pos-l-1 > 0){
            left = _verify(sequence,l,pos-1);
        }
        bool right = true;
        if(r - pos >0){
            right = _verify(sequence,pos,r-1);
        }
        return left && right;
    }
};

int main(){
    vector<int>  vec = {4,8,6,12,16,14,10};
    Solution s;
    cout<<s.VerifySquenceOfBST(vec)<<endl;
}
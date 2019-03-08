//
// Created by yin on 2019-02-26.
//
#include <vector>
#include <set>
#include <string>
#include <iostream>
using namespace std;


class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<int> vec;
        DFS(n,0,vec);
        return res;
    }


    void DFS(int n,int row,vector<int> vec){
        if(row >= n){
            string row;
            vector<string> tmp;
            for(int i=0;i<n;i++){
                string row;
                for(int j=0;j < n;j++){
                    if(j == vec[i]){
                        row +='Q';
                    }else{
                        row += '.';
                    }
                }
                tmp.push_back(row);
                cout<<row<<endl;
            }
            cout<<endl;
            res.push_back(tmp);
            return ;
        }

        for(int i=0; i< n; i++){
            if(col.find(i) != col.end() || pie.find(i+row) != pie.end() || na.find(i-row) != na.end()){
                continue;
            }
            col.insert(i);
            pie.insert(i+row);
            na.insert(i-row);

            vector<int> tmp = vec;
            vec.push_back(i);
            cout<<i<<endl;
            DFS(n,row+1,vec);

            vec = tmp;
            col.erase(i);
            pie.erase(i+row);
            na.erase(i-row);
        }

    }

    vector<vector<string> > res;
    set<int> col;
    set<int> pie;
    set<int> na;
};

int main(){
    Solution s;
    s.solveNQueens(4);
}
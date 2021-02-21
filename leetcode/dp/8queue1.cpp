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

      vector<int> output;
      DFS(n,0,output);

      vector<vector<string>>  resString;
      for(int i=0 ; i< res.size(); i++){
        vector<string> vs;
        vector<int> v=res[i];//2 1 3 0
        for(int j=0 ;j < n; j++){
          string s;
          for(int k=0; k<n; k++){
            if(v[j] == k){
              s.push_back('Q');
            }else{
              s.push_back('.');
            }
          }
          vs.push_back(s);
        }
        resString.push_back(vs);
      }

      return resString;

    }

    void DFS(int n, int row, vector<int> output){
      if(row >= n){
        res.push_back(output);
        return ;
      }

      for(int col=0; col < n ; col++){
        if(cols.count(col) >0 || pie.count(row+col) >0 || na.count(row-col) >0){
          continue;
        }
        cols.insert(col);
        pie.insert(row+col);
        na.insert(row-col);
        output.push_back(col);

        DFS(n,row+1,output);

        output.pop_back();

        cols.erase(col);
        pie.erase(row+col);
        na.erase(row-col);
      }

    }

    vector<vector<int>> res;
    set<int> cols,pie,na;
};

int main(){
    Solution s;
    s.solveNQueens(4);
}
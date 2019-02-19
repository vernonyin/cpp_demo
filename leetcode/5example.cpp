//
// Created by yin on 2019-01-12.
//

//1、递归

#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <cmath>
#include <vector>

using namespace std;

class Solution {
public:
    int recursion(int level) {
        //1、退出条件
        if (para1 <1){
            return ;
        }
        //2、数据处理
        process_data(pra);

        //3、下一层
        recursion(level+1)
        //4、返回
    }
    // 2^10=2*2
    double power(int x,int y){
        if (y <= 1){
            return
        }
    }

    double _power(int x,int y,int sum){
        if (y <= 1){
            return 1;
        }
        int sum *= x;
        return _power(x,y-1,sum);
    }

    int dfs(LiskNode* node,int visited){
       visited.add();
       for next_node : node.children(){
           if not visited{
               dfs(next_node,visited);
           }
       }

    }

    int search(vector<int> &nums, int target) {
        int i = 0, j = nums.size() - 1;
        while (i <= j) {
            int mid = i + (j - i) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] > target) {
                j = mid;
            } else {
                i = mid;
            }
        }
        return -1;
    }

    //bfs
    int maxDepth(TreeNode* root) {
        if (!root){
            return 0;
        }
        queue<TreeNode*> q;
        q.push(root);
        int res = 0;
        while(!q.empty()){
            res++;
            int n=q.size();
            for(int i=0; i<n;i++){
                TreeNode* p = q.front();
                q.pop();
                if (p->left){
                    q.push(p->left);
                }
                if(p->right){
                    q.push(p->right);
                }
            }
        }
        return res;
    }
}

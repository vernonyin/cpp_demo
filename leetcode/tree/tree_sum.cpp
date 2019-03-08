//
// Created by yin on 2019-02-25.
//

#include <vector>
#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
        val(x), left(NULL), right(NULL) {
    }
};

class Solution {
public:
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        int sum = 0;
        vector<int> vec;
        vector<vector<int> > res;
        _find(root,expectNumber,sum,vec,res);
        return res;
    }

    void _find(TreeNode* root,int expectNumber,int sum,vector<int> vec,vector<vector<int> >& res){
        if(root == NULL) return ;
        sum += root->val;
        vec.push_back(root->val);

        if(sum == expectNumber){
            res.push_back(vec);
        }
        vector<int> new_vec = vec;
        int new_sum = sum;
        if(root->left){
            _find(root->left,expectNumber,sum,vec,res);
        }
        if(root->right){
            _find(root->right,expectNumber,new_sum,new_vec,res);
        }
    }
};

int main(){
    vector<int>  vec = {4,8,6,12,16,14,10};
    //{10,5,12,4,7},22
    TreeNode* root = new TreeNode(10);
    TreeNode* root5 = new TreeNode(5);
    TreeNode* root12 = new TreeNode(12);
    TreeNode* root4 = new TreeNode(4);
    TreeNode* root7 = new TreeNode(7);
    root->left = root5;
    root->right = root12;
    root5->left = root4;
    root5->right = root7;
    Solution s;
    vector<vector<int> > res =s.FindPath(root,22);
    for(auto r:res){
        for(auto rr : r){
            cout<<rr<<" ";
        }
        cout<<endl;
    }
}
//
// Created by yin on 2019-02-09.
//

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
  bool isSymmetric(TreeNode* root) {
    if(root == NULL) return true;
    return _recur(root->left,root->right);
  }

  bool _recur(TreeNode* l,TreeNode* r){
    if(l == NULL && r == NULL) return true;
    if(l == NULL || r == NULL) return false;

    if(l->val != r->val) return false;
    return _recur(l->left,r->right) && _recur(l->right,r->left);
  }
};
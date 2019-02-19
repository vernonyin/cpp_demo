

#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <cmath>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;

  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
      vector<int> dep;
      while(root)
    }

  //树重建
  struct TreeNode *reConstructBinaryTree(vector<int> pre, vector<int> in) {

    //输入序列为空，返回
    if (in.size() == 0 || pre.size() == 0)
      return NULL;
    //将输入序列分成左右子树，用作递归
    vector<int> prel, prer, inl, inr;
    //当前的根节点
    TreeNode *head = new TreeNode(pre[0]);
    int index = 0;//找到中序遍历中根节点的位置
    for (int i = 0; i < in.size(); i++) {
      if (in[i] == pre[0]) {
        index = i;
        break;
      }
    }
    //根据根节点的位置，分成两个子树
    for (int i = 0; i < index; i++) {
      prel.push_back(pre[i + 1]);//根节点在第一，所以加1
      inl.push_back(in[i]);
    }
    for (int i = index + 1; i < pre.size(); i++) {
      inr.push_back(in[i]);
      prer.push_back(pre[i]);
    }
    //左，右子树的前序和中序序列输入，递归
    head->left = reConstructBinaryTree(prel, inl);
    head->right = reConstructBinaryTree(prer, inr);
    return head;
  }

  //判断是否是二叉搜索树
  bool isValidBST(TreeNode *root) {
    TreeNode *prev = NULL;
    return validate(root, prev);
  }

  bool validate(TreeNode *node, TreeNode *&prev) {
    if (node == NULL) return true;
    if (!validate(node->left, prev)) return false;

    if (prev != NULL && prev->val >= node->val) return false;
    prev = node;
    return validate(node->right, prev);
  }

  //最近公共结点
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    if (!root || root == p || root == q) return root;
    TreeNode *left = lowestCommonAncestor(root->left, p, q);
    TreeNode *right = lowestCommonAncestor(root->right, p, q);
    return !left ? right : !right ? left : root;
  }

  void PrintPre(struct TreeNode *root) {
    if (root == NULL)
      return;
    printf("%d", root->val);

    PrintPre(root->left);
    PrintPre(root->right);
  }

  //最大深度
  int maxDepth(TreeNode *root) {
    if (root == NULL) return 0;

    return root == NULL ? 0 : max(maxDepth(root->left), maxDepth(root->right)) + 1;
  }

  //最小深度
  int minDepth(TreeNode *root) {
    if (root == NULL) return 0;
    if (!root->left) return minDepth(root->right)+1;
    if (!root->right) return minDepth(root->left)+1;

    int leftMin = minDepth(root->left);
    int rightMin = minDepth(root->right);

    return min(leftMin,rightMin)+1;
  }


    bool isValidBST(TreeNode* root) {
      if(!root){
        return true;
      }
      vector<int> v;
      inOrder(root,v);
      for(int i=0;i<v.size()-1;i++){
        if(v[i] >= v[i+1]){
          return false;
        }
      }
      return true;
    }

    void inOrder(TreeNode* root,vector<int>& vec){
      if (!root){
        return ;
      }
      inOrder(root->left,vec);
      vec.push_back(root->val);
      inOrder(root->right,vec);
    }

    bool isValidBST(TreeNode* root) {
      if(!root || (!root->left && !root->right)){
        return true;
      }
      return isValid(root,NULL,NULL);
    }

    bool isValid(TreeNode* root,TreeNode* min,TreeNode*  max){
      if (!root) {
        return true;
      }
      if ((min != NULL && root->val <= min->val) || (max != NULL && root->val >= max->val)){
        return false;
      }
      return isValid(root->left,min,root) &&
             isValid(root->right,root,max);
    }
};

int main() {

  //{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}
  vector<int> pre = {1, 2, 4, 7, 3, 5, 6, 8};
  vector<int> in = {4, 7, 2, 1, 5, 3, 8, 6};

  Solution s;
  struct TreeNode *tree = s.reConstructBinaryTree(pre, in);
  s.PrintPre(tree);
  s.maxDepth(tree);
}
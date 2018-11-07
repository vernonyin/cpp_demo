
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <cmath>

using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool isValidBST(struct TreeNode* root) {

}


struct TreeNode * NewTree(){
    struct TreeNode *r = new(struct TreeNode);
    r->val=0;
    r->left =  new(struct TreeNode);
    r->right = new(struct TreeNode);
}

int main() {

}
#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//前序遍历
void preOrder(TreeNode *root){
    if(!root){
        return;
    }
    cout << root->val;
    preOrder(root->left);
    preOrder(root->right);
}
//中序遍历
void inorder(TreeNode *root){
    if(!root){
        return;
    }
    preOrder(root->left);
    cout << root->val;
    preOrder(root->right);
}
//后序遍历
void backorder(TreeNode *root){
    if(!root){
        return;
    }
    preOrder(root->left);
    preOrder(root->right);
    cout << root->val;
}
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

    }
};

int main(int argc, char *argv[]){
    {
        vector<int> preorder = {3,9,20,15,7};
        vector<int> inorder = {9,3,15,20,7};
        Solution sol;
        sol.buildTree(preorder, inorder);
    }
    return 0;
}
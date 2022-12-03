/*
请完成一个函数，输入一个二叉树，该函数输出它的镜像。
例如输入：
     4
   /   \
  2     7
 / \   / \
1   3 6   9
镜像输出：

     4
   /   \
  7     2
 / \   / \
9   6 3   1

示例 1：

输入：root = [4,2,7,1,3,6,9]
输出：[4,7,2,9,6,3,1]
*/

#include <iostream>
#include <stack>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* mirrorTree(TreeNode* root) {
        if(!root){
            return nullptr;
        }
        TreeNode *pNewRoot = new TreeNode(root->val);
        pNewRoot->left = mirrorTree(root->right);
        pNewRoot->right = mirrorTree(root->left);
        return pNewRoot;  
    }

    TreeNode* mirrorTree1(TreeNode* root) {
        if(!root){
            return nullptr;
        }
        std::stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()){

            TreeNode* p = st.top();
            st.pop();
            if(p->left) st.push(p->left);
            if(p->right) st.push(p->right);
            TreeNode *tmp = p->left;
            p->left = p->right;
            p->right = tmp;
        }
        return root;
    }
};
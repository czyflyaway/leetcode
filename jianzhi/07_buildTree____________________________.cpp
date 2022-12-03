/*
输入某二叉树的前序遍历和中序遍历的结果，请构建该二叉树并返回其根节点。

假设输入的前序遍历和中序遍历的结果中都不含重复的数字。

示例 1:
    3
   / \
  9  20
    /  \
   15   7
Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
Output: [3,9,20,null,null,15,7]
示例 2:

Input: preorder = [-1], inorder = [-1]
Output: [-1]
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i = 0; i < inorder.size(); ++i){
            map[inorder[i]] = i;
        }
        return help(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }
private:
    TreeNode* help(vector<int>& preOrder, int prel, int prer, vector<int>& inOrder, int inl, int inr){
        if(prel > prer){
            return nullptr;
        }
        int preRoot = prel;
        int inRoot = map[preOrder[preRoot]];

        TreeNode *root = new TreeNode(preOrder[preRoot]);
        int sizeOfLeftSubTree = inRoot - inl ;
        root->left = help(preOrder, prel + 1, prel + sizeOfLeftSubTree, inOrder, inl, inRoot - 1);
        root->right = help(preOrder, prel + sizeOfLeftSubTree + 1, prer, inOrder, inRoot + 1, inr);
        return root;

    }

    unordered_map<int, int> map;
};
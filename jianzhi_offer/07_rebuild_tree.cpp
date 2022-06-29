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

//前序遍历
void preOrder(TreeNode *root){
    if(!root){
        return;
    }
    cout << root->val << ",";
    preOrder(root->left);
    preOrder(root->right);
}
//中序遍历
void inOrder(TreeNode *root){
    if(!root){
        return;
    }
    inOrder(root->left);
    cout << root->val << ",";
    inOrder(root->right);
}
//后序遍历
void backOrder(TreeNode *root){
    if(!root){
        return;
    }
    backOrder(root->left);
    backOrder(root->right);
    cout << root->val << ",";
}
class Solution {
private:
    unordered_map<int, int> index;

public:
    TreeNode* myBuildTree(const vector<int>& preorder, const vector<int>& inorder, int preorder_left, int preorder_right, int inorder_left, int inorder_right) {
        if (preorder_left > preorder_right) {
            return nullptr;
        }
        
        //找到前序遍历中根节点为第一个节点
        int preRoot = preorder_left;
        //找到中序遍历中节点的索引
        int inRoot = index[preorder[preRoot]];

        TreeNode *root = new TreeNode(preorder[preRoot]);
        
        //得到左子树数量=中序遍历中根节点的索引-中序遍历的左边界
        int sizeLeftSubTree = inRoot - inorder_left;

        root->left = 
            myBuildTree(preorder, inorder, 
            preorder_left + 1,                  //根 左子树  右子树 ，所以preorder_left+1为左子树的左边界
            preorder_left + sizeLeftSubTree,    //preorder_left + sizeLeftSubTree(左子树数量) 为左子树的右边界
            inorder_left,//中序遍历  左子树  根 右子树  
            inRoot - 1
            );

        root->right = myBuildTree(preorder, inorder,
            preorder_left + sizeLeftSubTree + 1,
            preorder_right,
            inRoot +1,
            inorder_right
            );   
        return root;


        // // 前序遍历中的第一个节点就是根节点
        // int preorder_root = preorder_left;
        // // 在中序遍历中定位根节点
        // int inorder_root = index[preorder[preorder_root]];
        
        // // 先把根节点建立出来
        // TreeNode* root = new TreeNode(preorder[preorder_root]);
        // // 得到左子树中的节点数目
        // int size_left_subtree = inorder_root - inorder_left;
        // // 递归地构造左子树，并连接到根节点
        // // 先序遍历中「从 左边界+1 开始的 size_left_subtree」个元素就对应了中序遍历中「从 左边界 开始到 根节点定位-1」的元素
        // root->left = myBuildTree(preorder, inorder, preorder_left + 1, preorder_left + size_left_subtree, inorder_left, inorder_root - 1);
        // // 递归地构造右子树，并连接到根节点
        // // 先序遍历中「从 左边界+1+左子树节点数目 开始到 右边界」的元素就对应了中序遍历中「从 根节点定位+1 到 右边界」的元素
        // root->right = myBuildTree(preorder, inorder, preorder_left + size_left_subtree + 1, preorder_right, inorder_root + 1, inorder_right);
        // return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        // 构造哈希映射，帮助我们快速定位根节点
        for (int i = 0; i < n; ++i) {
            index[inorder[i]] = i;
        }
        return myBuildTree(preorder, inorder, 0, n - 1, 0, n - 1);
    }
};

int main(int argc, char *argv[]){
    {
        vector<int> preorder = {3,9,20,15,7};
        vector<int> inorder = {9,3,15,20,7};
        Solution sol;
        sol.buildTree(preorder, inorder);
        preOrder(sol.buildTree(preorder, inorder));
        cout << endl;
        inOrder(sol.buildTree(preorder, inorder));
        cout << endl;
        backOrder(sol.buildTree(preorder, inorder));
        cout  << endl;
    }


    {
        vector<int> preorder = {1,2,4,3,5,6,7,8};
        vector<int> inorder = {4,2,1,5,3,7,6,8};
        Solution sol;
        sol.buildTree(preorder, inorder);
        preOrder(sol.buildTree(preorder, inorder));
        cout << endl;
        inOrder(sol.buildTree(preorder, inorder));
        cout << endl;
        backOrder(sol.buildTree(preorder, inorder));
        cout  << endl;
    }
    return 0;
}
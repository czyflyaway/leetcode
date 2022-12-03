/*
从上到下打印出二叉树的每个节点，同一层的节点按照从左到右的顺序打印。

例如:
给定二叉树: [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
返回：

[3,9,20,15,7]

*/

#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(nullptr) {}
};

class Solution {
public:
    //放入同一vector
    vector<int> levelOrder(TreeNode* root) {
        if(!root){
            return vector<int>{};
        }
        vector<int> ret;
        queue<TreeNode*> que;
        
        que.push(root);
        while(!que.empty()){
            int size = que.size();
            for(int i = 0; i < size; ++i){
                TreeNode *node = que.front();
                que.pop();
                ret.push_back(node->val);
                if(node->left) que.push(node->left);
                if(node->right) que.push(node->right);
            }
        }
        return ret;
    }
    //按行存储
    vector<vector<int>> levelOrderByRow(TreeNode* root) {
        if(!root){
            return vector<vector<int>>{};
        }
        vector<vector<int>> ret;
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty()){
            vector<int> level;
            for(int i = que.size(); i >= 0; --i){
                TreeNode* node = que.front();
                que.pop();
                level.push_back(node->val);
                if(node->left) que.push(node->left);
                if(node->right) que.push(node->right);
            }
            ret.push_back(level);
        }
        return ret;
    }
}; 

int main(int argc, char *argv[]){
    return 0;
}
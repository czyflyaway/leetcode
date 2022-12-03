/*
给定一棵二叉搜索树，请找出其中第 k 大的节点的值。
示例 1:

输入: root = [3,1,4,null,2], k = 1
   3
  / \
 1   4
  \
   2
输出: 4
示例 2:

输入: root = [5,3,6,2,4,null,null,1], k = 3
       5
      / \
     3   6
    / \
   2   4
  /
 1
输出: 4
*/

#include <iostream>
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
    int kthLargest(TreeNode* root, int k) {
        this->k = k;
        midOrder(root);
        return res;
    }
private:
    vector<int> vec;
    int k, res = 0;
    void midOrder(TreeNode *root){
        if(nullptr == root)
            return;
        midOrder(root->right);
        if(0 == k) return;
        if(--k == 0) res = root->val;
        midOrder(root->left);
    }
};
int main(int argc, char * argv[]){

    return 0;
}
/*
给定一个二叉搜索树, 找到该树中两个指定节点的最近公共祖先。

百度百科中最近公共祖先的定义为：“对于有根树 T 的两个结点 p、q，最近公共祖先表示为一个结点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）。”

       6
    /    \
   2      8
  / \    / \
 0   4  7   9 
    / \
   3   5
示例 1:

输入: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
输出: 6 
解释: 节点 2 和节点 8 的最近公共祖先是 6。
示例 2:

输入: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4
输出: 2
解释: 节点 2 和节点 4 的最近公共祖先是 2, 因为根据定义最近公共祖先节点可以为节点本身。

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
    //递归
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root->val < p->val && root->val < q->val) return lowestCommonAncestor(root->right, p, q);
        if(root->val > p->val && root->val > q->val) return lowestCommonAncestor(root->left, p, q);
        return root;
    }
    //遍历两次
    TreeNode* lowestCommonAncestor1(TreeNode* root, TreeNode* p, TreeNode* q) {
        auto makeRoute = [](TreeNode *root, TreeNode *key, vector<TreeNode*> &route){
            while (root)
            {
                route.push_back(root);
                if(root->val < key->val){
                    root = root->right;
                }
                else if(root->val > key->val){
                    root = root->left;              
                }
                else{
                    break;
                }
            }        
        };
        int res = 0;
        vector<TreeNode*> routeP;
        makeRoute(root, p, routeP);
        vector<TreeNode*> routeQ;
        makeRoute(root, q, routeQ);

        TreeNode* ancestor;
        for (int i = 0; i < routeP.size() && i < routeQ.size(); ++i) {
            if (routeP[i] == routeQ[i]) {
                ancestor = routeP[i];
            }
            else {
                break;
            }
        }
        return ancestor;
    }

    //遍历一次
    TreeNode* lowestCommonAncestor1(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ancestor = root;
        while(ancestor){
            if(p->val < ancestor->val && q->val < ancestor->val){
                ancestor = ancestor->left;
            }
            else if(p->val > ancestor->val && q->val > ancestor->val){
                ancestor = ancestor->right;
            }
            else{
                break;
            }
        }
        return ancestor;
    }
};

int main(int argc, char *argv[]){

    return 0;
}
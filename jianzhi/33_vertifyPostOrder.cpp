/*
输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历结果。如果是则返回 true，否则返回 false。假设输入的数组的任意两个数字都互不相同。
参考以下这颗二叉搜索树：

     5
    / \
   2   6
  / \
 1   3
示例 1：

输入: [1,6,3,2,5]
输出: false
示例 2：

输入: [1,3,2,6,5]
输出: true
*/

#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    bool verifyPostorder(vector<int>& postorder) {
        return help(postorder, 0, postorder.size() - 1);
    }
    bool help(vector<int> &postOrder, int l, int r){
        if(l >= r){
            return true;
        }
        int m = l;
        while(postOrder[m] < postOrder[r]) m++;
        int p = m;
        while(postOrder[p] > postOrder[r]) p++;

        return p == r && help(postOrder, l, m - 1) && help(postOrder, m, r - 1);
    }
};
/*
输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字。
示例 1：

输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
输出：[1,2,3,6,9,8,7,4,5]
示例 2：

输入：matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
输出：[1,2,3,4,8,12,11,10,9,5,6,7]
 

限制：

0 <= matrix.length <= 100
0 <= matrix[i].length <= 100
*/

#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(0 == matrix.size())
            return {};
        int row = matrix.size();
        int col = matrix[0].size();
        int rightEdge = col - 1;
        int leftEdge = 0;
        int upEdge = 0;
        int bottomEdge = row - 1;

        vector<int> res;
        while(1){
            for(int i = leftEdge; i <= rightEdge; ++i)  res.push_back(matrix[upEdge][i]);
            if(++upEdge > bottomEdge)break;
            for(int i = upEdge; i <= bottomEdge; ++i)   res.push_back(matrix[i][rightEdge]);
            if(--rightEdge < leftEdge)  break;
            for(int i = rightEdge; i >= leftEdge; --i)  res.push_back(matrix[bottomEdge][i]);
            if(--bottomEdge < upEdge) break;
            for(int i = bottomEdge; i >= upEdge; --i)   res.push_back(matrix[i][leftEdge]);
            if(++leftEdge > rightEdge) break;
        }
        return res;
    }
};
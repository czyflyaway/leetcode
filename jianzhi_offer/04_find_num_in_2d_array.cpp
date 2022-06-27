/*
在一个 n * m 的二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。请完成一个高效的函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。

示例:
现有矩阵 matrix 如下：
[
  [1,   4,  7, 11, 15],
  [2,   5,  8, 12, 19],
  [3,   6,  9, 16, 22],
  [10, 13, 14, 17, 24],
  [18, 21, 23, 26, 30]
]
给定 target = 5，返回 true。
给定 target = 20，返回 false。
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    /*
        暴力搜索
    */
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        for(int i = 0; i < matrix.size(); ++i){
            for(int j = 0; j < matrix[i].size(); ++j){
                if(matrix[i][j] == target){
                    return true;
                }
            }
        }
        return false;
    }
    /*
        从左下角开始搜索，记左下角值为flag
        if(flag > target) 则在上方, i==;
        if(flag < target) 则在右侧，j++;
        if(llag == target) 找到
    */
    bool findNumberIn2DArray_1(vector<vector<int>>& matrix, int target) {
        
        int i = matrix.size() - 1;
        int j = 0;
        while(i >= 0 && j < matrix[i].size()){
            if(matrix[i][j] > target){
                i--;
            }
            else if(matrix[i][j] < target){
                j++;
            }
            else{
                return true;
            }
        }
        return false;
    }
    /*
        二分查找
    */
   bool findNumberIn2DArray_2(vector<vector<int>>& matrix, int target) {
    
   }
};
int main(int argc, char *argv[]){

    {
        std::vector<std::vector<int>> matrix =
        {
            {1,   4,  7, 11, 15},
            {2,   5,  8, 12, 19},
            {3,   6,  9, 16, 22},
            {10, 13, 14, 17, 24},
            {18, 21, 23, 26, 30}
        };
        int target = 31;
        Solution sol;
        cout << "result of find:" << boolalpha << sol.findNumberIn2DArray(matrix,  target) << endl;
    }

    {
        std::vector<std::vector<int>> matrix =
        {
            {1,   4,  7, 11, 15},
            {2,   5,  8, 12, 19},
            {3,   6,  9, 16, 22},
            {10, 13, 14, 17, 24},
            {18, 21, 23, 26, 30}
        };
        int target = 1;
        Solution sol;
        cout << "result of find:" << boolalpha << sol.findNumberIn2DArray_1(matrix,  target) << endl;
    }

    return 0;
}
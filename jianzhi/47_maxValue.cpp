/*
在一个 m*n 的棋盘的每一格都放有一个礼物，每个礼物都有一定的价值（价值大于 0）。
你可以从棋盘的左上角开始拿格子里的礼物，并每次向右或者向下移动一格、直到到达棋盘的右下角。给定一个棋盘及其上面的礼物的价值，请计算你最多能拿到多少价值的礼物？

示例 1:

输入: 
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
输出: 12
解释: 路径 1→3→5→2→1 可以拿到最多价值的礼物
*/

#include <vector>
using namespace std;

class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        if(0 == grid.size())
            return 0;
        
        vector<vector<int>> dp(grid.size() + 1, vector<int>(grid[0].size() + 1));
        int left = 0, up = 0, max = 0;
        for(int x = 1; x < dp.size(); ++x){
            for(int y = 1; y < dp[x].size(); ++y){
                dp[x][y] = std::max(dp[x - 1][y], dp[x][y - 1]) +  + grid[x - 1 ][y - 1];
            }
        }
        return dp[dp.size() - 1][dp[0].size() - 1];
    }
};

int main(int argc, char *argv[]){
    return 0;
}
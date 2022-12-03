/*
给定一个 m x n 二维字符网格 board 和一个字符串单词 word 。如果 word 存在于网格中，返回 true ；否则，返回 false 。

单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。
*/

#include <iostream>
#include <vector>
#include <utility>

using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int cols = board[0].size();
        for(int i = 0; i < rows; ++i){
            for(int j = 0; j < cols; ++j){
                if(dfs(board, word, i, j, 0))
                    return true;
            }
        }
        return false;
    }
private:
    bool dfs(vector<vector<char>> &board, string word, int i, int j, int k){
        int rows = board.size();
        int cols = board[0].size();
        if(i < 0 || i >= rows || j < 0 || j >= cols || board[i][j] != word[k])
            return false;
        if(k == word.size() - 1)
            return true;
        board[i][j] = '\0';//在些路径置为0,不再搜索此路径
        vector<pair<int, int>> offset = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        bool res = false;
        for(auto v : offset){
            res = res || dfs(board, word, i + v.first, j + v.second, k + 1);
        }
        board[i][j] = word[k];//恢复
        return res;
    }
};

// class Solution {
// public:
//     bool exist(vector<vector<char>>& board, string word) {
//         rows = board.size();
//         cols = board[0].size();
//         for(int i = 0; i < rows; i++) {
//             for(int j = 0; j < cols; j++) {
//                 if(dfs(board, word, i, j, 0)) return true;
//             }
//         }
//         return false;
//     }
// private:
//     int rows, cols;
//     bool dfs(vector<vector<char>>& board, string word, int i, int j, int k) {
//         if(i >= rows || i < 0 || j >= cols || j < 0 || board[i][j] != word[k]) return false;
//         if(k == word.size() - 1) return true;
//         board[i][j] = '\0';
//         bool res = dfs(board, word, i + 1, j, k + 1) || dfs(board, word, i - 1, j, k + 1) || 
//                       dfs(board, word, i, j + 1, k + 1) || dfs(board, word, i , j - 1, k + 1);
//         board[i][j] = word[k];
//         return res;
//     }
// };

int main(int argc, char *argv[]){
    {
        vector<vector<char>> board = {
            {'A','B','C','E'}, 
            {'S','F','C','S'}, 
            {'A','D','E','E'}
        };
        string word = "ABCCED";
        Solution sol;
        cout << "find:" << boolalpha <<  sol.exist(board, word) << endl;
    }
    return 0;
}
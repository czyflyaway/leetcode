/*
给定一个 m x n 二维字符网格 board 和一个字符串单词 word 。如果 word 存在于网格中，返回 true ；否则，返回 false 。

单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。

例如，在下面的 3×4 的矩阵中包含单词 "ABCCED"（单词中的字母已标出）。
A B C E
S F C S
A D E E 
示例 1：

输入：board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
输出：true
示例 2：

输入：board = [["a","b"],["c","d"]], word = "abcd"
输出：false
*/

#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if(0 == board.size()) return false;
        int rows = board.size();
        int cols = board[0].size();
        bool res = false;
        for(int i = 0; i < rows; ++i){
            for(int j = 0; j < cols; ++j){
                if(board[i][j] == word[0] && dfs(board, i, j, word, 0)) return true;
            }
        }
        return res;
    }
    bool dfs(vector<vector<char>> &board, int row, int col, string word, int wordIndex){
        if(row < 0 || row >= board.size()
            || col < 0 || col >= board[row].size()
            || board[row][col] != word[wordIndex])
            return false;
        if(wordIndex == word.size() - 1)
            return true;
        board[row][col] = '\0';
        bool res = dfs(board, row + 1, col, word, wordIndex + 1)
                || dfs(board, row - 1, col, word, wordIndex + 1)
                || dfs(board, row, col + 1, word, wordIndex + 1)
                || dfs(board, row, col - 1, word, wordIndex + 1);
        board[row][col] = word[wordIndex];
        return res;
    }
};

int main(int argc, char *argv[]){

    return 0;
}
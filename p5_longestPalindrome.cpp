/*
给你一个字符串 s，找到 s 中最长的回文子串。
示例 1：

输入：s = "babad"
输出："bab"
解释："aba" 同样是符合题意的答案。
示例 2：

输入：s = "cbbd"
输出："bb"

提示：
1 <= s.length <= 1000
s 仅由数字和英文字母组成
*/

#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int maxLen = 1;
        int begin = 0;
        int n = s.size();
        if(n < 2){
            return s;
        }
        vector<vector<int>> dp(n, vector<int>(n));

        for(int i = 0; i < n; ++i){
            dp[i][i] = true;
        }
        for(int L = 2; L <= n; ++L){
            for(int i = 0; i < n; ++i){
                int j = L + i - 1;
                if(j >= n){
                    break;
                }
                if(s[i] != s[j]){
                    dp[i][j] = false;
                } else {
                    if(j - i < 3){
                        dp[i][j] = true;
                    } else{
                        dp[i][j] = dp[i + 1][j - 1];
                    }
                }

                if(dp[i][j] && j - i + 1 > maxLen){
                    maxLen = j - i + 1;
                    begin = i;
                }
            }
        }
        return s.substr(begin, maxLen);

    }
};

int main(int argc, char *argv[]){

    return 0;
}
/*
输入一个字符串，打印出该字符串中字符的所有排列。
你可以以任意顺序返回这个字符串数组，但里面不能有重复元素。

示例:

输入：s = "abc"
输出：["abc","acb","bac","bca","cab","cba"]
 

限制：

1 <= s 的长度 <= 8
*/

#include <vector>
#include <string>
#include <set>

using namespace std;
class Solution {
public:
    vector<string> permutation(string s) {
        dfs(s, 0);
    }
    void dfs(string s, int x){
        if(x == s.size() - 1){
            res.push_back(s);
            return;
        }
        set<int> st;
        for(int i = x; i < s.size(); ++i){
            
        }
    }
    vector<string> res;
};
/*
请实现一个函数，把字符串 s 中的每个空格替换成"%20"。

 

示例 1：

输入：s = "We are happy."
输出："We%20are%20happy."

*/
#include <iostream>
using namespace std;
class Solution {
public:
    // string replaceSpace(string s) {
    //     std::string ret;
    //     for(auto c : s){
    //         if(' ' == c){
    //             ret += "%20";
    //         } else
    //             ret += c;
    //     }
    //     return ret;
    // }

    string replaceSpace(string s) {
        int spaceCount = 0;
        for(auto c : s){
            if(c == ' ')
                spaceCount++;
        }
        int len = s.size();
        s.resize(len+ spaceCount * 2);

        for(int i = len - 1, j = s.size() - 1; i < j; --i, --j){
            if(s[i] != ' '){
                s[j] = s[i];
            } else {
                s[j - 2] = '%';
                s[j - 1] = '2';
                s[j] = '0';
                j -= 2;
            }
        }
        return s;
    }
};
int main(int argc, char *argv[]){
    std::string s = "We are happy.";
    Solution sol;
    std::cout << sol.replaceSpace(s) << std::endl;;
}
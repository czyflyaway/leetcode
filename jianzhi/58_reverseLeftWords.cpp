/*
字符串的左旋转操作是把字符串前面的若干个字符转移到字符串的尾部。请定义一个函数实现字符串左旋转操作的功能。比如，输入字符串"abcdefg"和数字2，该函数将返回左旋转两位得到的结果"cdefgab"。
示例 1：

输入: s = "abcdefg", k = 2
输出: "cdefgab"
示例 2：

输入: s = "lrloseumgh", k = 6
输出: "umghlrlose"

*/
#include <iostream>
using namespace std;
class Solution {
public:
    // string reverseLeftWords(string s, int n) {
    //     int size = s.size();
    //     if(0 == size || n >= size)
    //         return s;
    //     const int left = n;
    //     const int right = size - n;
    //     char *strLeft = new char[n];
    //     char *strRight = new char[size - n];
    //     char *str = const_cast<char *>(s.c_str());
    //     memcpy(strLeft, str, left);
    //     memcpy(strRight, str + left, right);
    //     memcpy(str, strRight, right);
    //     memcpy(str + right, strLeft, left);
    //     delete[] strLeft;
    //     delete[] strRight;
    //     return s;
    // }
    string reverseLeftWords(string s, int n) {
        int size = s.size();
        if(0 == size || n >= size)
            return s;
        
    }    
};

int main(int argc, char *argv[]){
    std::string s = "abcdefg";
    Solution sol;
    std::cout << sol.reverseLeftWords(s, 2) << std::endl;
}
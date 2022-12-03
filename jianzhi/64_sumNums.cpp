/*
求 1+2+...+n ，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）。

示例 1：

输入: n = 3
输出: 6
示例 2：

输入: n = 9
输出: 45
*/

#include <iostream>
#include <vector>
#include <string>
class Solution {
public:
    int sumNums(int n) {
        n && (n += sumNums(n - 1));
        return n;
    }
    //快速乘
    int mul(int a, int b){
        int ans = 0;
        while(b != 0){
            if(b & 1){
                ans += a;
            }
            b >>= 1;
            a <<= 1;
        }
        return ans;
    }
    int pow(int a, int b){
        int ans = 1;
        while(b != 0){
            if(b & 1){
                ans *= a;
            }
            b >>= 1;
            a *= a;
        }
        return ans;
    }
};

int main(int argc, char *argv[]){
    if(argc < 5)
        return -1;
    int a = std::stoi(argv[1]);
    int b = std::stoi(argv[2]);
    int c = std::stoi(argv[3]);
    int d = std::stoi(argv[4]);
    Solution sol;
    std::cout << sol.mul(a, b) << "\t" << sol.pow(c, d) <<std::endl;
    return 0;
}
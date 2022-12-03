/*
实现 pow(x, n) ，即计算 x 的 n 次幂函数（即，xn）。不得使用库函数，同时不需要考虑大数问题。
示例 1：

输入：x = 2.00000, n = 10
输出：1024.00000
示例 2：

输入：x = 2.10000, n = 3
输出：9.26100
示例 3：

输入：x = 2.00000, n = -2
输出：0.25000
解释：2-2 = 1/22 = 1/4 = 0.25
*/

#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        long an = abs(n);
        double ans = 1.0;
        while(an != 0){
            if(an & 1){
                ans *= x;
            }
            an >>= 1;
            x *= x;
        }
        return n >= 0 ? ans : 1.0 / ans;
    }
};

int main(int argc, char *argv[]){

    return 0;
}
/*
一只青蛙一次可以跳上1级台阶，也可以跳上2级台阶。求该青蛙跳上一个 n 级的台阶总共有多少种跳法。

答案需要取模 1e9+7（1000000007），如计算初始结果为：1000000008，请返回 1。

示例 1：

输入：n = 2
输出：2
示例 2：

输入：n = 7
输出：21
示例 3：

输入：n = 0
输出：1

*/

#include <iostream>
class Solution {
public:
    //递归
    int numWays(int n) {
        if(0 == n || 1 == n) return 1;
        if(2 == n) return 2;
        return numWays(n - 1) % mod + numWays(n - 2) % mod;
    }

    //迭代
    int numWays1(int n) {
        int f0 = 1;
        int f1 = 1;
        if(0 == n || 1 == n) return f0;
        int fn = 0;
        for(int i = 2; i <= n; ++i){
            fn = (f0 % mod + f1 % mod) % mod;
            f0 = f1;
            f1 = fn;
        }
        return fn;
    }

private:
    int mod = 1e9 + 7;
};

int main(int argc, char *argv[]){

    return 0;
}
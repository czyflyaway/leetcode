/*
给定一个数组 A[0,1,…,n-1]，
请构建一个数组 B[0,1,…,n-1]，
其中 B[i] 的值是数组 A 中除了下标 i 以外的元素的积, 即 B[i]=A[0]×A[1]×…×A[i-1]×A[i+1]×…×A[n-1]。
不能使用除法。

 
示例:

输入: [1,2,3,4,5]
输出: [120,60,40,30,24]
 
提示：

所有元素乘积之和不会溢出 32 位整数
a.length <= 100000
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> constructArr(vector<int>& a) {
        vector<int> res(a.size(), 1);
        int temp = 1;
        for(int i = 0; i < a.size(); ++i){
            res[i] = temp;
            temp *= a[i];
        }
        temp = 1;
        for(int i = a.size() - 1; i >= 0; --i){
            res[i] *= temp;
            temp *= a[i];
        }
        return res;
    }
};
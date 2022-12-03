/*
一个整型数组 nums 里除两个数字之外，其他数字都出现了两次。请写程序找出这两个只出现一次的数字。要求时间复杂度是O(n)，空间复杂度是O(1)。
示例 1：

输入：nums = [4,1,4,6]
输出：[1,6] 或 [6,1]
示例 2：

输入：nums = [1,2,10,4,1,4,3,3]
输出：[2,10] 或 [10,2]

限制：
2 <= nums.length <= 10000
*/

#include <vector>
#include <unordered_set>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        int ret = 0;
        for(auto i : nums){
            ret ^= i;
        }
        int div = 1;
        while(0 == (ret & div)){
            div <<= 1;
        }
        int a = 0, b = 0;
        for(auto i : nums){
            if(div & i){
                a ^= i;
            } else{
                b ^= i;
            }
        }
        return vector<int>{a, b};
    }
};


int main(int argc, char *argv[]){

    return 0;
}
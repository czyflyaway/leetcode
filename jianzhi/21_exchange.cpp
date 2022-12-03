/*
输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有奇数在数组的前半部分，所有偶数在数组的后半部分。
示例：

输入：nums = [1,2,3,4]
输出：[1,3,2,4] 
注：[3,1,2,4] 也是正确的答案之一。

*/

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        int left = 0; 
        int right = nums.size() - 1;

        while(left < right){
            if(1 == nums[left] % 2){
                ++left;
                continue;
            }
            if(0 == nums[right] % 2){
                --right;
                continue;
            }
            int temp = nums[left];
            nums[left] = nums[right];
            nums[right] = temp;
        }
        return nums;
    }
};

int main(int argc, char *argv[]){

    return 0;
}
/*
一个长度为n-1的递增排序数组中的所有数字都是唯一的，并且每个数字都在范围0～n-1之内。在范围0～n-1内的n个数字中有且只有一个数字不在该数组中，请找出这个数字。
示例 1:
输入: [0,1,3]
输出: 2

示例 2:
输入: [0,1,2,3,4,5,6,7,9]
输出: 8
*/

#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int size = nums.size();
        int sumN = (0 + size) * (size + 1) / 2;
        int sumVec = 0;
        for(auto i : nums){
            sumVec += i;
        }
        return sumN - sumVec;
    }
    int missingNumbe1(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while(left <= right){
            int mid = left + (right - left) >> 1;
            if(nums[mid] == mid){
                left = mid + 1;
            }
            else{
                right = mid - 1;
            }
        }
        return left;
    }
};

int main(int argc, char *argv[]){

    return 0;
}
/*
统计一个数字在排序数组中出现的次数。

 

示例 1:

输入: nums = [5,7,7,8,8,10], target = 8
输出: 2
示例 2:

输入: nums = [5,7,7,8,8,10], target = 6
输出: 0

*/
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        //折半查找
        //1、递归
        //2、迭代
        int left = 0;
        int right = nums.size() -1;
        int targetIndex = -1;
        int mid = -1;
        while(left <= right){
            mid = left + (right - left) / 2;

            if(nums[mid] == target){
                targetIndex = mid;
                break;
            } else if(nums[mid] > target){
                right = mid - 1;
            } else {
                left = mid + 1;
            }           
        }   
        if(-1 == targetIndex){
            return 0;
        }
        int time = 1;
        for(int i = targetIndex + 1; i < nums.size(); ++i){
            if(target == nums[i]){
                time++;
            } else{
                break;
            }
        }
        for(int i = targetIndex - 1; i >= 0; --i){
            if(target == nums[i]){
                time++;
            } else{
                break;
            }
        }
        return time;
    }
    // int binarySearch(vector<int> nums, int left, int right){

    // }
};

int main(int argc, char *argv[]){
    std::vector<int> v = {1,3};
    Solution sol;
    std::cout << sol.search(v, 1) << std::endl;
}
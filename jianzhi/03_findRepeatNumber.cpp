/*
找出数组中重复的数字。


在一个长度为 n 的数组 nums 里的所有数字都在 0～n-1 的范围内。数组中某些数字是重复的，但不知道有几个数字重复了，也不知道每个数字重复了几次。请找出数组中任意一个重复的数字。

示例 1：

输入：
[2, 3, 1, 0, 2, 5, 3]
输出：2 或 3 

*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;
class Solution {
public:
    // int findRepeatNumber(vector<int>& nums) {
    //     unordered_set<int> set;
    //     for(auto val : nums){
    //         if(set.find(val) != set.end()){
    //             return val;
    //         }
    //         set.insert(val);
    //     }
    //     return -1;
    // }
    int findRepeatNumber(vector<int>& nums) {
        for(int i = 0; i < nums.size();){
            if(nums[i] == i){
                ++i;
                continue;
            }
            if(nums[i] == nums[nums[i]])
                return nums[i];
            swap(nums[i], nums[nums[i]]);
        }
        return -1;


        /*
                int i = 0;
        while(i < nums.size()) {
            if(nums[i] == i) {
                i++;
                continue;
            }
            if(nums[nums[i]] == nums[i])
                return nums[i];
            swap(nums[i],nums[nums[i]]);
        }
        return -1;
        */
    }
};
int main(int argc, char *argv[]){

    return 0;
}
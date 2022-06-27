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
#include <unordered_set>

using namespace std;

void swap(int &l, int &r){
    l = l ^ r;
    r = l ^ r;
    l = l ^ r;
}
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        std::unordered_set<int> num_set;
        for(int i = 0; i < nums.size(); ++i){
            if(num_set.find(nums[i]) != num_set.end()){
                return nums[i];
            }
            num_set.insert(nums[i]);
        }
        return -1;
    }
    int findRepeatNumber_1(vector<int>& nums) {
        int len = nums.size();
        for(int i = 0; i < len;){
            if(nums[i] == i){
                ++i;
                continue;
            }
            if(nums[i] == nums[nums[i]]){
                return nums[i];
            }
            swap(nums[i], nums[nums[i]]);

        }
        return -1;
    }
};

int main(int argc, char *argv[]){
    {
        std::vector<int> arr = {2, 3, 1, 0, 2, 5, 3};
        Solution sol;
        cout << "repeat num index:" << sol.findRepeatNumber(arr) << endl;
    }
    {
        std::vector<int> arr = {2, 3, 1, 0, 2, 5, 3};
        Solution sol;
        cout << "repeat num index:" << sol.findRepeatNumber_1(arr) << endl;
    }
}
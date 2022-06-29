#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        if(0 == right){
            if(target == nums[0]){
                return true;
            }
            return false;
        }

        while(left <= right){
            int mid = left + (right - left) / 2;
            if(nums[mid] == target){
                return true;
            } else if(nums[mid > target]){
                
            }

        }
    }
};

int main(int argc, char* argv[]){
    {

    }
    return 0;
}
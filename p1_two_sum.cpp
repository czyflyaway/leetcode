#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> mapResult;//<value, index>
        for(int i = 0; i < nums.size(); ++i)
        {
            int need = target - nums[i];
            if(mapResult.find(need) != mapResult.end()){
                return std::vector<int>{mapResult[need], i};
                // return std::vector<int>({mapResult[need], i});
            }
            mapResult[nums[i]] = i;
        }
        return std::vector<int>();
    }
};

int main(int argc, char *argv[])
{
    {
        vector<int> nums = {2, 7, 11, 15};
        int target = 9;
        std::vector<int> result;
        Solution solution;
        result = solution.twoSum(nums, target);
        for(auto index : result)
        {
            cout << index << "\n";
        }
        cout << "\n";
    }

    {
        vector<int> nums = {3,2,4};
        int target = 6;
        std::vector<int> result;
        Solution solution;
        result = solution.twoSum(nums, target);
        for(auto index : result)
        {
            cout << index << "\n";
        }
        cout << "\n";
    }
    {
        vector<int> nums = {3,3};
        int target = 6;
        std::vector<int> result;
        Solution solution;
        result = solution.twoSum(nums, target);
        for(auto index : result)
        {
            cout << index << "\n";
        }
        cout << "\n";
    }

    {
        vector<int> nums = {3,5,6,1,9,13};
        int target = 15;
        std::vector<int> result;
        Solution solution;
        result = solution.twoSum(nums, target);
        for(auto index : result)
        {
            cout << index << "\n";
        }
        cout << "\n";
    }

    return 0;
}
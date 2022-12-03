/*
在一个数组 nums 中除一个数字只出现一次之外，其他数字都出现了三次。请找出那个只出现一次的数字。
示例 1：

输入：nums = [3,4,3,3]
输出：4
示例 2：

输入：nums = [9,1,7,9,7,9,7]
输出：1
 

限制：

1 <= nums.length <= 10000
1 <= nums[i] < 2^31
*/
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> map;
        for(auto v : nums){
            if(map.find(v) != map.end()){
                map[v] = map[v] + 1;
                continue;
            }
                
            map[v] = 1;
        }
        for(auto val : map){
            if(1 == val.second){
                return val.first;
            }
        }
        return -1;
    }
};
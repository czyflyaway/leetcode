/*
数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
你可以假设数组是非空的，并且给定的数组总是存在多数元素。
示例 1:

输入: [1, 2, 3, 2, 2, 2, 5, 4, 2]
输出: 2
 
限制：
1 <= 数组长度 <= 50000
*/


#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        //1、哈希表存储之后，取大于n / 2 次数的元素
        unordered_map<int, int> map;
        for(auto i : nums){
            if(map.find(i) != map.end()){
                map[i] += 1;
            }
            else{
                map[i] = 1;
            }
        }
        int count = nums.size() / 2 + 1;
        for(auto iter : map){
            if(iter.second >= count){
                return iter.first;
            }
        }
        return -1;
    }
};

int main(int argc, char *argv[]){

    return 0;
}
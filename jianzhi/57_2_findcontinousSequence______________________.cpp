/*
输入一个正整数 target ，输出所有和为 target 的连续正整数序列（至少含有两个数）。

序列内的数字由小到大排列，不同序列按照首个数字从小到大排列。
示例 1：

输入：target = 9
输出：[[2,3,4],[4,5]]
示例 2：

输入：target = 15
输出：[[1,2,3,4,5],[4,5,6],[7,8]]
 
限制：

1 <= target <= 10^5
*/

#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        vector<vector<int>> res;
        int limit = (target - 1) / 2;
        int sum = 0;
        for(int i = 1; i <= limit; ++i){
            for(int j = i; ; ++j){
                sum += j;
                if(sum > target){
                    sum = 0;
                    break;
                } else if(sum == target){
                    vector<int> one;
                    for(int k = i; k <= j; ++k){
                        one.push_back(k);
                    }
                    res.push_back(one);
                    sum = 0;
                    break;
                }
            }
        }
        return res;
    }


    vector<vector<int>> findContinuousSequence1(int target) {
        vector<vector<int>> vec;
        vector<int> res;
        for(int l = 1, r = 2; l < r;){
            int sum = (l + r) * (r - l + 1) / 2;
            if(sum == target){
                res.clear();
                for(int i = l; i <= r; ++i){
                    res.push_back(i);
                }
                vec.emplace_back(res);
                sum = 0;
                l++;
            }
            else if(sum < target){
                r++;
            } else{
                l++;
            }
        }
        return vec;
    }
    vector<vector<int>> findContinuousSequence(int target) {
        vector<vector<int>>vec;
        vector<int> res;
        for (int l = 1, r = 2; l < r;){
            int sum = (l + r) * (r - l + 1) / 2;
            if (sum == target) {
                res.clear();
                for (int i = l; i <= r; ++i) {
                    res.emplace_back(i);
                }
                vec.emplace_back(res);
                l++;
            } else if (sum < target) {
                r++;
            } else {
                l++;
            }
        }
        return vec;
    }
};
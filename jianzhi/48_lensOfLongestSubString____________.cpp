/*
请从字符串中找出一个最长的不包含重复字符的子字符串，计算该最长子字符串的长度。

示例 1:

输入: "abcabcbb"
输出: 3 
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
示例 2:

输入: "bbbbb"
输出: 1
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
示例 3:

输入: "pwwkew"
输出: 3
解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
*/

#include <iostream>
#include <unordered_map>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        int size = s.size();
        int start = 0;
        unordered_map<char, int> map_ch_pos;
        for(int end = 0; end < size; ++end){
            char ch = s[end];
            if(map_ch_pos.find(ch) != map_ch_pos.end()){
                start = std::max(start, map_ch_pos[ch] + 1);
            }
            ans = std::max(ans, end - start + 1);
            map_ch_pos[ch] = end;
        }
        return ans;
    }
    int lengthOfLongestSubstring1(string s){
        if(s.size() < 2){
            return s.size();
        }
        int ans = 0;
        unordered_map<char, int> map;
        int left = 0;
        for(int right = 0; right < s.size(); ++right)
        {
            char ch = s[right];
            if(map.find(ch) != map.end()){
                left = std::max(left, map[ch] + 1);
            }
            ans = std::max(ans, right - left + 1);
            map[ch] = right;
        }
        return ans;
        
    }
};

int main(int argc, char *argv[]){

    return 0;
}
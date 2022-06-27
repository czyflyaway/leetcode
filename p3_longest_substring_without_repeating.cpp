#include <iostream>
#include <deque>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int right = 0;
        std::string noRepeaterString;
        std::string maxStr;
        int maxLen = 0;
        while(right < s.size()){
            int pos = maxStr.find(s[right]);
            if(std::string::npos == pos){
                maxStr.push_back(s[right]);
                right++;
            }
            else{
                if(maxStr.size() > maxLen){
                    noRepeaterString = maxStr;
                    maxLen = maxStr.size();
                }
                //找到字符串之后
                //maxStr往后移1位
                maxStr.push_back(s[right]);
                maxStr = maxStr.substr(pos + 1);
                right++;
            }
        }
        if(maxStr.size() > maxLen){
            noRepeaterString = maxStr;
            maxLen = maxStr.size();
        }
        printf("resultstring:%s\n", noRepeaterString.c_str());
        return maxLen;
    }
};

int main(int argc, char *argv[])
{
    {
        std::string s = "abcabcbb";
        Solution sol;
        int maxLen  = sol.lengthOfLongestSubstring(s);
        printf("longest len:%d\n", maxLen);
    }
    {
        std::string s = "bbbbb";
        Solution sol;
        int maxLen  = sol.lengthOfLongestSubstring(s);
        printf("longest len:%d\n", maxLen);
    }
    {
        std::string s = "dvdf";
        Solution sol;
        int maxLen  = sol.lengthOfLongestSubstring(s);
        printf("longest len:%d\n", maxLen);
    }
    return 0;
}
#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    string replaceSpace(string s) {
        std::string result;
        int spaceCount = 0;
        for(int i = 0; i < s.size(); ++i){
            if(s[i] == ' '){
                spaceCount++;
            }
        }
        result.resize(s.size() + 2 * spaceCount);
        for(int i = 0, j = 0; i < s.size() && j < result.size(); ++i){
            if(s[i] == ' '){
                result[j++] = '%';
                result[j++] = '2';
                result[j++] = '0';
            } else{
                result[j++] = s[i];
            }
        }
        return result;
    }

    /*
        原地修改， 当i == j 时结束
    */
    string replaceSpace_1(string s) {
        int spaceCount = 0;
        for(int i = 0; i < s.size(); ++i){
            if(s[i] == ' '){
                spaceCount++;
            }
        }
        int len = s.size();
        s.resize(len +  2 * spaceCount);
        for(int i = len - 1, j = s.size() - 1; i < j; --i){
            if(s[i] == ' '){
                s[j--] = '0';
                s[j--] = '2';
                s[j--] = '%';
            } else{
                s[j--] = s[i];
            }
        }
        return s;
    }
};

int main(int argc, char *argv[]){
    {
        std::string s = "We are happy.";
        Solution sol;
        cout << sol.replaceSpace(s) << endl;
    }

    {
        std::string s = "We are happy.";
        Solution sol;
        cout << sol.replaceSpace_1(s) << endl;
    }
}
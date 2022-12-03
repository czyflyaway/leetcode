#include <iostream>
#include <vector>
#include <string>

#include <cmath>

using namespace std;

class Solution {
public:
    vector<int> printNumbers(int n) {
        int max = pow(10, n);
        vector<int> ret;
        for(int i(1); i < max; ++i){
            ret.push_back(i);
        }
        return ret;
    }
    //模拟加法运算
    vector<int> printNumbers_1(int n) {
        vector<int> ret;

        auto increase = [](string &s) -> bool {
            bool overFlow = false;
            int carry = 0;
            for(int i = s.size() - 1; i >= 0; --i){

                int current = s[i] - '0' + carry;
                if(i == s.size() - 1) current += 1;
                if(current > 9){
                    if(0 == i){
                        overFlow = true;
                    } else{
                        carry = 1;
                        s[i] = current - 10 + '0';
                    }
                } else {
                    s[i] = current + '0';
                    break;
                }
            }
            return overFlow;
        };
        auto pushNum = [&ret](string s) {
            int firstNotzeroIndex = -1;
            for(int i = 0; i < s.size(); ++i){
                if('0' != s[i]){
                    firstNotzeroIndex = i;
                    break;
                }
            }
            if(firstNotzeroIndex != -1){
                 std::string actualNumStr = s.substr(firstNotzeroIndex);
                 ret.push_back(stoi(s.substr(firstNotzeroIndex)));
            } else{
                ret.push_back(0);
            }
        };
        string s(n, '0');
        while(!increase(s)){
            pushNum(s);
        }

        return ret;
    }
    //使用全排列
    vector<int> printBigNumbers_2(int n) {
        return vector<int>();
    }
};

int main(int argc, char *argv[]){
    {
        int n = 2;
        Solution sol;
        vector<int> res = sol.printNumbers(n);
        for(auto v : res){
            cout << v << ",";
        }
        cout << endl;
    }

    {
        int n = 2;
        Solution sol;
        vector<int> res = sol.printNumbers_1(n);
        for(auto v : res){
            cout << v << ",";
        }
        cout << endl;
    }
    return 0;
}
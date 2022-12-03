#include <iostream>
using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ret  = 0;
        for(int i = 0; i < 32; ++i){
            if(n & (1 << i))
                ret++;
        }
        return ret;
    }
    int hammingWeight_1(uint32_t n) {
        int ret = 0;
        while(n){
            n = n & (n - 1);
            ret++;
        }
        return ret;
    }
};

int main(int argc, char *argv[]){
    {
        int n = 11;
        Solution sol;
        cout << sol.hammingWeight(n) << endl;
    }
        {
        int n = 11;
        Solution sol;
        cout << sol.hammingWeight_1(n) << endl;
    }
    return 0;
}
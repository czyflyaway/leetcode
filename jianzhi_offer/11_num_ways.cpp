#include <iostream>
using namespace std;


#include <vector>

class Solution {
public:
    int numWays(int n) {
        if(0 == n) return 1;
        if(1 == n) return 1;

        int mod = 1e9 + 7;
        vector<int> dp(n + 1, 1);
        for(int i = 2; i <= n; ++i){
            dp[i] = (dp[i - 1] % mod+ dp[i - 2] % mod) % mod;
        }
        return dp[n];
    }

    int numWays_1(int n) {
        if(0 == n) return 1;
        if(1 == n) return 1;

        int mod = 1e9 + 7;
        int fn = 0;
        int f0 = 1;
        int f1 = 1;
        for(int i = 2; i <= n; ++i){
            fn = (f0 % mod + f1 % mod) % mod;
            f0 = f1;
            f1 = fn;
        }
        return fn;
    }
};
int main(int argc, char *argv[]){

    {
        Solution sol;
        cout << sol.numWays(atoi(argv[1])) << endl;
    }

    {
        Solution sol;
        cout << sol.numWays(atoi(argv[1])) << endl;
    }
    return 0;
}
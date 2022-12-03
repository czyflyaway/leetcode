#include <iostream>
using namespace std;

class Solution {
public:
    int fib(int n) {
        if (0 == n) {
            return 0;
        }
        if(1 == n){
            return 1;
        }
        return fib(n - 1) + fib(n - 2);
    }

    int fib_1(int n) {
        if (n < 2) {
            return n;
        }
        int mod = 1e9 + 7;
        int f1 = 1, f2 = 0, ret;
        for(int i = 2; i <= n; ++i){
            ret = (f1 + f2) % mod;
            f2 = f1;
            f1 = ret;          
        }
        
        return ret;
    }
};

int quick_pow(int a,int b){
	int ans = 1;
	while(b){
		if(b&1) ans *= a;
		a *= a;
		b >>= 1;
	}
	return ans;
}
int main(int argc, char *argv[]){
    {
        int n = 43;
        Solution sol;
        cout << sol.fib_1(n) << endl;
    }
    {
        cout << quick_pow(2, 5) << endl;
    }
    return 0;
}
#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    double myPow(double x, int m) {
        int n = abs(m);
        if(0 == n)
            return 1.0;
        double ans = myPow(x, n / 2);
        double ret = n % 2 ? ans * ans * x : ans * ans;
        return m < 0 ? 1 / ret : ret;
    }

    double myPow_1(double x, int n) {
        double ret = 1.0;
        int m = abs(n);
        double xTemp = x;
        while( m > 0){
            if(m % 2){
                ret *= xTemp;
            }
            xTemp *= xTemp;
            m /= 2;
        }
        return n < 0 ? 1.0 / ret : ret;
    }
};

int main(int argc, char *argv[]){
    {
        double x = 2.0;
        int n = -2;
        Solution sol;
        cout << sol.myPow(x, n) << endl;
    }

    {
        double x = 2.0;
        int n = -2;
        Solution sol;
        cout << sol.myPow_1(x, n) << endl;
    }
    return 0;
}
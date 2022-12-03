#include "fast_mul_pow.h"

int fast_mul(int a, int b){
    int ans = 0;
    while(b != 0){
        if(b & 1){
            ans += a;
        }
        b >>= 1;
        a <<= 1;
    }
    return ans;
}

int fast_pow(int a, int b){
    int ans = 1;
    while(b != 0){
        if(b & 1){
            ans *= a;
        }
        b >>= 1;
        a *= a;
    }
    return ans;
}

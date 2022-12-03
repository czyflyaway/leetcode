/*
假设把某股票的价格按照时间先后顺序存储在数组中，请问买卖该股票一次可能获得的最大利润是多少？
示例 1:

输入: [7,1,5,3,6,4]
输出: 5
解释: 在第 2 天（股票价格 = 1）的时候买入，在第 5 天（股票价格 = 6）的时候卖出，最大利润 = 6-1 = 5 。
     注意利润不能是 7-1 = 6, 因为卖出价格需要大于买入价格。
示例 2:

输入: [7,6,4,3,1]
输出: 0
解释: 在这种情况下, 没有交易完成, 所以最大利润为 0。
*/

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size = prices.size();
        int maxProfit = 0;
        int minPrice = 1e9;
        for(int i = 0; i < prices.size(); ++i){
            maxProfit = std::max(maxProfit, prices[i] - minPrice);
            minPrice = std::min(minPrice, prices[i]);
        }
        return maxProfit;
    }
};

int main(int argc, char *argv[]){

    return 0;
}
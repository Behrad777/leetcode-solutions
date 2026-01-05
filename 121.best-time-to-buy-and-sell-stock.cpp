/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 */

// @lc code=start

#include <vector>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {

        auto min_price = prices[0];
        auto max_profit = 0;
        
        for(size_t i{1}; i < prices.size(); ++i){
            int current_profit = prices[i] - min_price;

            if(current_profit > max_profit) max_profit = current_profit;
            if(prices[i]<min_price) min_price = prices[i];
        }

        return max_profit;
        
    }
};
// @lc code=end


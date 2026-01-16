/*
 * @lc app=leetcode id=123 lang=cpp
 *
 * [123] Best Time to Buy and Sell Stock III
 */

// @lc code=start

#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        size_t size = prices.size();
        // vector<int> dp_buy_1(size, -prices[0]); //cost of buying
        // vector<int> dp_sell_1(size, 0); //max profit at point if I sell at this point based on all previous points
        // vector<int> dp_buy_2(size, -prices[0]);
        // vector<int> dp_sell_2(size, 0);
       int dp_buy_1{-prices[0]};
       int dp_sell_1{0};
       int dp_buy_2{-prices[0]};
       int dp_sell_2{0};
        //instead of vectors, we only care about the i-1 value so just keep track of a variable
        for(size_t i{1}; i<size; ++i){
            // dp_buy_1[i] = max(dp_buy_1[i-1], -prices[i]); //best case cost buying
            // dp_sell_1[i] = max(dp_sell_1[i-1], prices[i] + dp_buy_1[i]); //best of selling from the previous one or selling now
            
            // dp_buy_2[i] = max(dp_buy_2[i-1], dp_sell_1[i]-prices[i]); //best of the previous or buy here
            // dp_sell_2[i] = max(dp_sell_2[i-1], dp_buy_2[i] + prices[i]); //best of previous or sell here
            
            dp_buy_1 = max(dp_buy_1, -prices[i]); //can we get a better deal? if not take the most recent best deal of buying
            dp_sell_1 = max(dp_sell_1, prices[i] + dp_buy_1); //best of all previous sells or sell now 

            dp_buy_2 = max(dp_buy_2, dp_sell_1 - prices[i]); //best of previous buys or buy here
            dp_sell_2 = max(dp_sell_2, dp_buy_2 + prices[i]);

        }
        return dp_sell_2;
    }

};

// @lc code=end



int main(){
    Solution sol;
    vector<int> test = {1,2,4,2,5,7,2,4,9,0};

    cout << sol.maxProfit(test);


}
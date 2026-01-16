/*
 * @lc app=leetcode id=122 lang=cpp
 *
 * [122] Best Time to Buy and Sell Stock II
 */

#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {

        auto iter = prices.begin();
        
        for(; iter<prices.end()-1; ++iter){ //check the 2nd last element cuz we compare it to the last one, we can buy and sell incrementally 
            if(*iter < *next(iter)){ //if the next price is bigger, buy on the current and sell on the next (use std next to prevent incrementing it)
                max_profit += *next(iter) - *iter;
            }
            //otherwise skip
        }
        
        return max_profit;
    }

private:    
    int max_profit{0};
};
// @lc code=end
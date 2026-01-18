/*
 * @lc app=leetcode id=29 lang=cpp
 *
 * [29] Divide Two Integers
 */

// @lc code=start
using namespace std;
#include <cmath>
#include <bitset>

class Solution {
public:
    int divide(int dividend, int divisor) {
        long long result = 0;

        if(dividend ==0){
            return 0;
        }

        if (dividend == INT_MIN && divisor == -1){
            return INT_MAX;
        }
        
        bool negative = (dividend < 0) ^ (divisor < 0);


        //if the divisor is a positive power of 2 
        if(bitset<32>(divisor).count()==1 && divisor > 0){

            auto shift = (long long)log2(divisor);
            return dividend >> shift;
        }

        //else, do long division oh my goodness

        long long a = llabs((long long) dividend);
        long long b = llabs((long long) divisor);

         for (int shift = 31; shift >= 0; shift--) {
            if ((a >> shift) >= b) {
                a -= (b << shift); //if b is smaller subtract
                result += (1LL << shift); //add a 1 to the result wherever we found 
            }
        }

        if (negative) result = -result;

        //round to int max and min 
        if (result > INT_MAX) return INT_MAX;
        if (result < INT_MIN) return INT_MIN;

        return (int)result;

    }
};
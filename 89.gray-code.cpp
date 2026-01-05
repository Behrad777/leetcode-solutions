/*
 * @lc app=leetcode id=89 lang=cpp
 *
 * [89] Gray Code
 */

// @lc code=start
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> result;
        int num=0;
        grayCalc(result, n, num);
        return result;
    }

    void grayCalc(vector<int>& result, int n, int& cur_num){
        if(n==0){
            result.push_back(cur_num);
            return;
        }

        //dont flip the bit
        grayCalc(result, n-1, cur_num);

        //flip the nth bit of cur_num 

        cur_num = cur_num ^ (1<<(n-1));
        grayCalc(result, n-1, cur_num);

    }
};
// @lc code=end


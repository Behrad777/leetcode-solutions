/*
 * @lc app=leetcode id=11 lang=cpp
 *
 * [11] Container With Most Water
 */

// @lc code=start

#include <vector>
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
        auto leftPtr = height.begin();
        auto rightPtr = height.end() -1;
        auto maxArea{0};

        while(leftPtr != rightPtr){ //theyll meet at some point 
            if(*leftPtr <= *rightPtr){ //handle the area calculation and incrementing at the same time, left is smaller or the same
                int area = std::distance(leftPtr, rightPtr) * (*leftPtr);
                maxArea = (area>maxArea) ? area : maxArea;
                leftPtr++;
            } 
            else if(*leftPtr > *rightPtr){ //right is smaller
                int area = std::distance(leftPtr, rightPtr) * (*rightPtr);
                maxArea = (area>maxArea) ? area : maxArea;
                rightPtr--;
            }
        }

        return maxArea;
    }
};
// @lc code=end


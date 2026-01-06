/*
 * @lc app=leetcode id=704 lang=cpp
 *
 * [704] Binary Search
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int size = nums.size() -1;
        int index = binarySearch(0, size, target, nums);
        return index;
        
    }

    int binarySearch(int start, int end, int target, vector<int>& nums){ //recursively call

        if(start>end) return -1;

        int mid = (start+end) >> 1; //easier on the runtime, bit shift integer division
        
        if(nums[mid] == target){
            return mid; //we found the index
        }
        else if (target < nums[mid]){ //its on the left side of the middle
            return binarySearch(start, mid-1, target, nums); //left start the same, right should be mid-1
        }
        else if (target > nums[mid]){ //its on the right side of the middle
            return binarySearch(mid+1, end, target, nums); //start at mid+1
        }
        return -1;
    }
};
// @lc code=end


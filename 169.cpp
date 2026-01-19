#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        for(auto n: nums){
            frequency_table[n]++; //if it exists, increment the times appeared by 1, if it doesnt exst, it hashes and we get 1
            if(frequency_table[n] > majority_pair.second){ //if it has higher frequency
                //make it the most frequent number with its frequency
                majority_pair.first = n;
                majority_pair.second = frequency_table[n];

            }
        }
        return majority_pair.first;
    }

private:
unordered_map<int, int> frequency_table; //maps the number-> times appeared

pair<int,int> majority_pair{0,0}; //has the number, times appeared
};

//there is always a majority element
/*

Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.
Example 1:

Input: nums = [3,2,3]
Output: 3

Example 2:

Input: nums = [2,2,1,1,1,2,2]
Output: 2

 */

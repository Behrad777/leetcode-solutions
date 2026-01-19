#include <iterator>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) { //returns k, the size of the new unduplicated array

        //one placing iterator that actually does stuff, and we compare the scouting iterator to it
        //we should never edit the first value anyway

        auto placing_iterator = nums.begin();
        auto scouting_iterator = nums.begin();

        while(scouting_iterator!=nums.end()){

            if(*scouting_iterator != *placing_iterator){
                placing_iterator++;
                *placing_iterator = *scouting_iterator;
            }
            scouting_iterator++;
        }

        //then, from whatever is left from the placing iterator, erase the rest of the vector
        return distance(nums.begin(), placing_iterator) +1;

    }

private:
};

int main(){
    Solution soln;
    vector<int> nums = {1,1,2,};
    cout << soln.removeDuplicates(nums);
}



/*
Input: nums = [0,0,1,1,1,2,2,3,3,4]
Output: 5, nums = [0,1,2,3,4,_,_,_,_,_]
Explanation: Your function should return k = 5, with the first five elements of nums being 0, 1, 2, 3, and 4 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).
*/

//how 2 pointers? something with it being sorted
// start at index 0, we have a placing pointer and a scouting pointer,
// //while the scouting pointer isnt at the end of the array
//  if the current value is the same, keep incremening
//  if we reach a new number, increment the placing pointer and set the value to the scouting pointer just once

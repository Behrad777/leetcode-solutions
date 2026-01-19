#include <cstdint>
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size()==1) return 1;

        //first 2 elements should be chilling

        auto placing_iterator = nums.begin();
        auto scouting_iterator = nums.begin()+1;

        while(scouting_iterator!=nums.end()){

            if(*scouting_iterator == *placing_iterator && duplicates_used < 2){ //the same number, place it if we have less than 2 duplicates
                cout <<"same num \n";
                placing_iterator++;
                *placing_iterator = *scouting_iterator;
                duplicates_used++;
            } else if(*scouting_iterator != *placing_iterator){ // on a transition between 2 numbers, place it and make duplicates 1
                cout << "transitioning \n";
                placing_iterator++;
                *placing_iterator = *scouting_iterator;
                duplicates_used=1;
            }
            //otherwise, we have more than 2 duplicates so just keep going
            cout<<"increment scout \n";
            scouting_iterator++;
        }

        //then, from whatever is left from the placing iterator, erase the rest of the vector
        return distance(nums.begin(), placing_iterator) +1;

    }

private:
int8_t duplicates_used{1};
};

int main(){

    vector<int> nums{1,2};
    Solution soln;
    soln.removeDuplicates(nums);

    for(auto x: nums){
        cout<< x << endl;
    }
}

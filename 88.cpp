#include <iterator>
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(m ==0){
            nums1 = nums2; //copy constructor
            return;
        }
        if(n==0) return;

        auto nums1_iter = nums1.begin();
        advance(nums1_iter, m-1); //starts where the elements end

        auto nums2_iter = nums2.end()-1;

        auto placing_iter = nums1.end() -1; //last element in nums1 we start placing
        //start from the end of both vectors

        while(nums2_iter >=nums2.begin()){
            if (nums1_iter == nums1.begin() && m!=1) {
                cout<<"num1 iter is finished \n";
                  *placing_iter = *nums2_iter;
                  if (placing_iter != nums1.begin()) --placing_iter;
                  if (nums2_iter == nums2.begin()) break;
                  --nums2_iter;
                  continue;
              }
            if(*nums2_iter >=*nums1_iter){ //nums2 has the bigger value
                cout << "num2 iter is bigger \n";
                *placing_iter = *nums2_iter;
                nums2_iter--; //decrement it until the beginning
            } else{ //num1 has the bigger one
                cout<<"num1 is bigger \n";
                *placing_iter = *nums1_iter;
                nums1_iter--;
            }
            if(placing_iter!=nums1.begin()) placing_iter--;

        }


    }
};

int main(){

    Solution soln;
    std::vector<int> nums1 = {2,0};
    std::vector<int> nums2 = {1};

    soln.merge(nums1, 1, nums2, 1);

    for(auto x : nums1){
        cout<< x << endl;
    }

}


//nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
// nums1 iterator should be at nums1[m-1] 2 in this case
// nums2 iterator should be at nums2[n-1] 2 in this case
// then a placing iterator (also in nums1) is at end() -1, so the last 0
// then we see which one is bigger, then place it there, then decrement the ones we placed
//holy fuck c++

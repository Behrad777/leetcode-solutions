#include <algorithm>
#include <future>
#include <vector>
#include <queue>
using namespace std;



//k is for sure less than or equal to nums.size
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> max_heap;
        int max_value;

        for(auto num : nums){
            max_heap.push(num);
        }

        for(size_t i{0}; i<k-1; ++i){
            max_heap.pop();
        }


        return max_heap.top();

    }
};

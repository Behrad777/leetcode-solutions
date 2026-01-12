using namespace std;
#include <vector>
#include <deque>

//specialized for sliding window because we only give a shit about the value at the front 
class MonotonicQueue {
private:
    deque<int> dq;
public:

    void push(int x) {
        while (!dq.empty() && dq.back() < x) {
            dq.pop_back();
        }
        dq.push_back(x);
    }

    //pop the element leaving the sliding window
    //if it's the front, pop it, otherwise it will get ovewritten by something later 
    void pop(int x) {
        if (!dq.empty() && dq.front() == x) {
            dq.pop_front();
        }
    }

    int max() const {
        return dq.front();
    }
};

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        //EDGE CASES
        if(k==1){
            return nums;
        }
        vector<int> result;

        auto window_start_iter = nums.begin();
        auto window_end_iter = nums.begin() + (k -1); //includes the start and end 

        if(k == nums.size()){
            const auto& max = std::max_element(nums.begin(), nums.end()); //this is an iterator, so deref and put it in a vector
            return {*max};
        }

        MonotonicQueue queue_inst;


        //put them all into a monotonic queue 
        for(auto i{window_start_iter}; i<window_end_iter; ++i){
            queue_inst.push(*i); //push the actual value not the index 
        }

        while (window_end_iter != nums.end()){ //after last elemnt + 1 we can stop
            queue_inst.push(*window_end_iter);
            result.push_back(queue_inst.max());

            queue_inst.pop(*window_start_iter);

            window_start_iter++;
            window_end_iter++;
        }

        return result;
        
    }
};
// @lc code=end


#include <cstddef>
#include <queue>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
       int best_profit{w};
       priority_queue<int> max_heap;
       vector<pair<int,int>> pairs;
       auto size = profits.size();

       for(auto i{0uz}; i<size; ++i){
           pairs.push_back({capital[i], profits[i]});
       }
       sort(pairs.begin(), pairs.end());


       size_t i{0}; //for iterating in the pairs
       while(k--){ //remove the need to keep a counter

           while(i<size && (pairs[i].first <= best_profit)){ //oob check as well
               max_heap.push(pairs[i].second); //push the profit
               ++i;
           }

           //now choose the best one
           if(!max_heap.empty()){

               best_profit+= max_heap.top();
               max_heap.pop();
           }
       }

       return best_profit;

    }
};

int main(){
    //test
    Solution sol;
    vector<int> profits = {1,2,3};
    vector<int> capital = {0,1,1};
    int k = 2;
    int w = 0;
    int result = sol.findMaximizedCapital(k, w, profits, capital);
    cout << "Maximized Capital: " << result << endl;

}

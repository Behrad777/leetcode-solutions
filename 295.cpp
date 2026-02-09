#include <algorithm>
#include <functional>
#include <iostream>
#include <queue>
#include <vector>

using namespace std; //just for my ide
class MedianFinder {
public:
    MedianFinder() {} //nothing needed here

    void addNum(int num) {
        max_heap.push(num);
        min_heap.push(max_heap.top());
        max_heap.pop();

        if(max_heap.size() < min_heap.size()){
            max_heap.push(min_heap.top());
            min_heap.pop();
        }

    }

    double findMedian() {

        if(max_heap.size() > min_heap.size()){
            return (double)max_heap.top();
        } else{
            return (max_heap.top()+min_heap.top()) / 2.0;
        }
    }

private:
priority_queue<int> max_heap; //left triangle
priority_queue<int, vector<int>, greater<int>> min_heap; //right triangle
};

//put items in the left macx heap first (assuming new number belongs in lower half)
// then rebalance if we need to

int main(){

    MedianFinder mf;
    mf.addNum(6);
    mf.addNum(10);
    mf.addNum(2);
    mf.addNum(6);
    mf.addNum(5);
    cout<<"median is "<<mf.findMedian()<<'\n'; //should be 6
}

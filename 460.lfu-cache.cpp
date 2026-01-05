/*
 * @lc app=leetcode id=460 lang=cpp
 *
 * [460] LFU Cache
 */

// @lc code=start

#include <unordered_map>
#include <list>

using namespace std;

struct Node {
    //sizes optimised to be just above the next unsigned integer 
    int key;
    int freq;
    int value;
};

class LFUCache {
public:
    LFUCache(int capacity): capacity_(capacity)  {}
    
    int get(int key) {
        auto entry = keyTable.find(key);
        if(entry == keyTable.end()) return -1; //if we didnt find it, return -1 not found
        //otherwise it exists, and we need to increase its freqency then adjust the frequency table
        //we have the iterator so no need to search the whole list 
        auto nodeIter = entry->second; //iterator into the list 
        Node node = *nodeIter; //copy the node so we can move into higher freq

        int oldFreq = node.freq;
        freqTable[oldFreq].erase(nodeIter); //erase the old node from the frequency table

        //update the minfreq if it was the oldFreq
        if (freqTable[oldFreq].empty()) {
            freqTable.erase(oldFreq);
            if (minFreq_ == oldFreq) {
                minFreq_++;
            }
        }
        
        node.freq++;

        freqTable[node.freq].push_back(node);
        auto newIter = std::prev(freqTable[node.freq].end()); //one before .end is the last element in the list

        entry->second = newIter; //update the keytable to point to new iterator

        return node.value;
    }
    
    void put(int key, int value) {

        //if the key exists, update value + increase frequency 
        auto entry = keyTable.find(key);
        if(entry != keyTable.end()){
            auto nodeIter = entry->second;
            nodeIter->value = value;

            Node node = *nodeIter; //copy the node so we can move into higher freq

            int oldFreq = nodeIter->freq;
            freqTable[oldFreq].erase(nodeIter); //erase the old node from the frequency table
            
            //erase the now empty old frequency bucket 
            if (freqTable[oldFreq].empty()) {
                freqTable.erase(oldFreq);
                if (minFreq_ == oldFreq) {
                    minFreq_++;
                }
            }
            
            node.freq++;

            freqTable[node.freq].push_back(node);
            auto newIter = std::prev(freqTable[node.freq].end()); //one before .end is the last element in the list

            entry->second = newIter; //update the keytable to point to new iterator
            return; //finished here, all we needed to do
        } 

        //if the capacity is full

        if(capacity_ == keyTable.size()){ //max number of keys

            auto &listLFU = freqTable[minFreq_]; //list of all nodes that have the minimum frequency
            auto victim = listLFU.front(); //the LRU + LFU is the one at the front of the list
            keyTable.erase(victim.key); //remove the LRU+LFU from the keytable
            //remove the LFU+LRU from the frequency table 
            listLFU.pop_front();

            //now if that was the last element in that frequency bucket, delete that frequency 
            if (listLFU.empty()) {
                freqTable.erase(minFreq_);
            }
        }

        //now we can insert the new node
        Node node = {key, 1, value}; //starts at freq 1
        freqTable[1].push_back(node); //put it in the freq 1 bucket
        //now get the iterator to this so we can put it in the keytable
        auto newIter = std::prev(freqTable[1].end()); //one before .end is the last element in the list
        keyTable[key] = newIter;
        minFreq_ =1; //now we have a new min freq of 1
    }

private:
    size_t capacity_;
    int minFreq_ =1;

    unordered_map<int, list<Node>::iterator> keyTable; //keys to node iterator
    unordered_map<int, list<Node>> freqTable; //frequency buckets

};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end


#include <queue>
#include <unordered_set>
#include <vector>
#include <string>
#include <iostream>
using namespace std;


class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {

        //put the bank into an unordered set to remove the ones we already used
        //unordered set has a constructor that takes iterators to the start and end of a vector and makes it there
        unordered_set<string> words_set(bank.begin(), bank.end());

        queue<pair<string,int>> queue;

        queue.push({startGene, 0}); //starts at the 0th level if our start is our end is takes 0 mutations

        while(!queue.empty()){
            //copy value, iterations, we dont wanna edit the orignal
            auto [word, iterations] = queue.front(); queue.pop();

            if(word == endGene) return iterations;

            //otherwise, try all combinations of a new word with ACGT and if it matches add it to the queue

            for(size_t i{0}; i<word.length(); ++i){
                for(auto c : {'A', 'C', 'G','T'}){
                    //create a copy of the word so its not remembdering each charatcer edit
                    string possible_word = word;
                    possible_word[i]=c;
                    //now take out edited word, see if its in the set
                    if(words_set.contains(possible_word)){
                        queue.push({possible_word, iterations+1});
                        words_set.erase(possible_word);
                        //debug
                        cout << "possible word: " << possible_word << endl;
                    }

                }
            }
        }
        return -1; //queue empty but

    }
};


int main(){
    //test like this Input: sInput: startGene = "AACCGGTT", endGene = "AAACGGTA", bank = ["AACCGGTA","AACCGCTA","AAACGGTA"]
    Solution sol;
    vector<string> bank = {"AACCGGTA","AACCGCTA","AAACGGTA"};
    cout << sol.minMutation("AACCGGTT", "AAACGGTA", bank) << endl;
}

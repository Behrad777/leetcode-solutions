/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 */

 using namespace std;
 #include<stack>
 #include<string>

// @lc code=start
class Solution {
public:
    bool isValid(string s) {
        
        if(s.size()<2) return false; //cant have a valid parentheses less than 2
        
        if(s[0] == ']' || s[0] == ')' || s[0] == '}') return  false; //cant start with closing parentheses 
        

        for(char iter: s){

            switch(iter){
                //opening brackets are placed onto the stack 
                case('('):
                    parentheses.push('(');
                    break;
                
                case('{'):
                    parentheses.push('{');
                    break;
            
                case('['):
                    parentheses.push('[');
                    break;
                
            
                    //closing brackets are checked against the top and pop if its correct
                case(')'):
                    if(parentheses.empty()) return false;
                    if(parentheses.top() == '('){
                        parentheses.pop();
                    } else return false;
                    break;
                
                case('}'):
                    if(parentheses.empty()) return false;
                    if(parentheses.top() == '{'){
                        parentheses.pop();
                    } else return false;
                    break;

                case(']'):
                    if(parentheses.empty()) return false;
                    if(parentheses.top() == '['){
                        parentheses.pop();
                    } else return false;
                    break;      
            } 
        }
        return parentheses.empty();


    }

private:
    //stack has to be empty at the end for it to make sense
    // opening brackets are pushed onto the stack
    //closing brackets are checked against the top, if the top is the other version, then pop it, great, otherwise, the stack will fill up, and its wrong
    stack<char> parentheses;
};

// @lc code=end


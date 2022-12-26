#include <iostream>
#include <stack>
#include <unordered_map>

/*
    Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

    An input string is valid if:

    Open brackets must be closed by the same type of brackets.
    Open brackets must be closed in the correct order.
    Every close bracket has a corresponding open bracket of the same type.
    

    Example 1:

    Input: s = "()"
    Output: true
*/

class Solution {
public:
    bool isValid(std::string s) {
        std::stack<char> par;
        std::unordered_map<char, char> map = {
            {']','['}, 
            {')','('}, 
            {'}','{'}
        };

        // if the char is an opening bracket then we push it onto the stack
        for (auto c: s) {
            if(c=='[' || c=='(' || c=='{') {
                par.push(c);
            } else if(!par.size() || par.top() != map[c]) {    // if we have a closing bracket without an opening one or it's not the good bracket we return false
                return false;
            } else {    // if we get matched a pair bracket
                par.pop();
            }
        }

        // if the stack is empty then it's valid
        return par.empty();

    }
};

int main() {
    Solution sol;
    std::string s = "()[]{}";

    if (sol.isValid(s))
    {
        std::cout << "It's valid" << std::endl;
    } else {
        std::cout << "It's not valid" << std::endl;
    }
    

    return 0;
}
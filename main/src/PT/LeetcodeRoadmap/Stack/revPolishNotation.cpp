#include <iostream>
#include <stack>
#include <vector>

/*
    You are given an array of strings tokens that represents an arithmetic expression in a Reverse Polish Notation.

    Evaluate the expression. Return an integer that represents the value of the expression.

    Note that:

    The valid operators are '+', '-', '*', and '/'.
    Each operand may be an integer or another expression.
    The division between two integers always truncates toward zero.
    There will not be any division by zero.
    The input represents a valid arithmetic expression in a reverse polish notation.
    The answer and all the intermediate calculations can be represented in a 32-bit integer.
    

    Example 1:

    Input: tokens = ["2","1","+","3","*"]
    Output: 9
    Explanation: ((2 + 1) * 3) = 9
*/

class Solution {
public:
    int evalRPN(std::vector<std::string>& tokens) {
        std::stack<int> s;

        for (int i = 0; i < tokens.size(); i++)
        {
            if((tokens[i] != "+") && (tokens[i] != "/") && (tokens[i] != "*") && (tokens[i] != "-")){
                long long int num = 0, chk = 1;

                for(int j = 0; j < tokens[i].size(); j++)
                {
                    if(tokens[i][j] == '-') {
                        chk =- 1; 
                        continue;
                    }
                    num += (tokens[i][j] - '0');
                    num *= 10;
                }
                num /= 10;
                if(chk == -1) {
                    num *= -1;
                }
                
                s.push(num);
            }
            else if(tokens[i] == "+") {
                long long int t1 = s.top();
                s.pop();
                long long int t2 = s.top();
                s.pop();
                
                s.push(t1+t2);
            }
            else if(tokens[i] == "-") {
                long long int t1 = s.top();
                s.pop();
                long long int t2 = s.top();
                s.pop();
                
                s.push(t1-t2);
            }
            else if(tokens[i] == "*"){
                long long int t1 = s.top();
                s.pop();
                long long int t2 = s.top();
                s.pop();
                
                s.push(t1*t2);
            }
            else if(tokens[i] == "/"){
                long long int t1 = s.top();
                s.pop();
                long long int t2 = s.top();
                s.pop();
                
                s.push(t1/t2);
            }
        }
        
        return s.top();
    }
};

int main() {
    std::vector<std::string> tokens = {"2", "1", "+", "3", "*"};
    Solution s;

    std::cout << s.evalRPN(tokens) << std::endl;

    return 0;
}
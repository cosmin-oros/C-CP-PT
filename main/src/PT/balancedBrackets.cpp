#include <iostream>
#include <stack>

using namespace std;

bool areBracketsBalanced(string expr){
    // stack to hold the previous brackets
    stack<char> temp;

    for (int i = 0; i < expr.length(); i++)
    {
        // if the stack is empty we push the bracket in there 
        if (temp.empty())
        {
            temp.push(expr[i]);
        }else if ((temp.top() == '(' && expr[i] == ')') ||
                    (temp.top() == '{' && expr[i] == '}') ||
                    (temp.top() == '[' && expr[i] == ']'))
        {
            // if there is a pair we pop it from the stack
            temp.pop();
        }else{
            temp.push(expr[i]);
        }
        
    }

    // if we still have something on the stack it means that the brackets are not balanced
    if (temp.empty())
    {
        return true;
    }else{
        return false;
    }
    

}

int main(){
    string expr = "{()}[]";

    if (areBracketsBalanced(expr))
    {
        cout << "Brackets are balanced" << endl;
    }else{
        cout << "Brackets are not balanced" << endl;
    }
    

    return 0;
}
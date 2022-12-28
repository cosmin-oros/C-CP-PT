#include <iostream>
#include <stack>
#include <vector>

/*
    Given an array of integers temperatures represents the daily temperatures, return an array answer such that answer[i] 
    is the number of days you have to wait after the ith day to get a warmer temperature. 
    If there is no future day for which this is possible, keep answer[i] == 0 instead.

    Example 1:

    Input: temperatures = [73,74,75,71,69,72,76,73]
    Output: [1,1,4,2,1,1,0,0]
*/

class Solution {
public:
    std::vector<int> dailyTemperatures(std::vector<int>& temperatures) {
        std::vector<int> answer(temperatures.size(), 0);
        std::stack<int> s;

        for (int i = 0; i < temperatures.size(); i++)
        {
            while (!s.empty() && (temperatures[i] > temperatures[s.top()]))
            {
                answer[s.top()] = abs(s.top() - i);
                s.pop();
            }

            s.push(i);
        }
        
        return answer;
    }
};

int main() {
    std::vector<int> temperatures = {73, 74, 75, 71, 69, 72, 76, 73};
    Solution s;

    std::vector<int> output = s.dailyTemperatures(temperatures);

    for (auto i = output.begin(); i < output.end(); i++)
    {
        std::cout << *i << " ";
    }
    std::cout << std::endl;

    return 0;
}
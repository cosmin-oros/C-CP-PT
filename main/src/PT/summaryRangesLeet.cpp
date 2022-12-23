#include <iostream>
#include <vector>
#include <string>

/*
    You are given a sorted unique integer array nums.

    A range [a,b] is the set of all integers from a to b (inclusive).

    Return the smallest sorted list of ranges that cover all the numbers in the array exactly. 
    That is, each element of nums is covered by exactly one of the ranges, 
    and there is no integer x such that x is in one of the ranges but not in nums.

    Each range [a,b] in the list should be output as:

    "a->b" if a != b
    "a" if a == b
    

    Example 1:

    Input: nums = [0,1,2,4,5,7]
    Output: ["0->2","4->5","7"]
    Explanation: The ranges are:
    [0,2] --> "0->2"
    [4,5] --> "4->5"
    [7,7] --> "7"
*/

class Solution {
public:
    std::vector<std::string> summaryRanges(std::vector<int>& nums) {
        std::vector<std::string> result;
        
        int n = nums.size();
		
        if(n == 0) {
            return result;
        }
 
        int a = nums[0];
        
        for(int i = 0; i < n; i++)
        {
            if((i == n-1) || (nums[i]+1 != nums[i+1])) {
                if(nums[i] != a) {
                    result.push_back(std::to_string(a)+ "->"+ std::to_string(nums[i]));
                }
					
                else {
                    result.push_back(std::to_string(a));
                }

                if(i != n-1) {
                    a = nums[i+1];
                }
            }
        }

        return result;
    }
};

int main() {
    Solution s;
    std::vector<int> nums = {0, 1, 2, 4, 5, 7};

    std::vector<std::string> ranges = s.summaryRanges(nums);
    
    for (auto i = ranges.begin(); i < ranges.end(); i++)
    {
        std::cout << *i << " ";
    }
    std::cout << std::endl;
    

    return 0;
}
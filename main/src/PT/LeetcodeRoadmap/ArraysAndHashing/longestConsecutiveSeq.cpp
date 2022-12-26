#include <iostream>
#include <vector>
#include <algorithm>

/*
    Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

    You must write an algorithm that runs in O(n) time.

    Example 1:

    Input: nums = [100,4,200,1,3,2]
    Output: 4
    Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
*/

class Solution {
public:
    int longestConsecutive(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        int prev = nums.at(0);
        int cons = 1;
        int maxCons = 1;

        for (int i = 1; i < nums.size(); i++)
        {
            if (nums.at(i) == prev+1)
            {
                cons++;
                if (cons > maxCons)
                {
                    maxCons = cons;
                }
                
            } else {
                cons = 1;
            }
            prev = nums.at(i);          
        }
        
        return maxCons;
    }
};

int main() {
    std::vector<int> nums = {100, 4, 200, 1, 3, 2};
    Solution s;

    std::cout << s.longestConsecutive(nums) << std::endl;

    return 0;
}
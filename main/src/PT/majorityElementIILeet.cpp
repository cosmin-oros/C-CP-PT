#include <iostream>
#include <vector>
#include <algorithm>

/*
    Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.

    Example 1:

    Input: nums = [3,2,3]
    Output: [3]
*/

class Solution {
public:
    std::vector<int> majorityElement(std::vector<int>& nums) {
        int n = nums.size() / 3;
        int count = 0;
        std::vector<int> apps;

        // sort the elements in the vector
        std::sort(nums.begin(), nums.end());

        // check for the elements that appear more than n/3 times

        for (auto i = nums.begin(); i < nums.end(); i++)
        {
            int temp = *i;

            while (*i == temp)
            {
                count++;
                i++;
            }

            if (count > n)
            {
                apps.assign(1, temp);
            }

            count = 0;
            
        }

        return apps;
        
    }

};

int main() {
    std::vector<int> nums = {3, 2, 3};
    Solution s;

    std::vector<int> majElem = s.majorityElement(nums);

    for (auto i = majElem.begin(); i < majElem.end(); i++)
    {
        std::cout << *i << " ";
    }
    std::cout << "\n";
    

    return 0;
}
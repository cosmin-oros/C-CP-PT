#include <iostream>
#include <vector>
#include <set>

/*
    Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.

    Example 1:

    Input: nums = [1,2,3,1]
    Output: true
*/

class Solution {
public:
    bool containsDuplicate(std::vector<int>& nums) {
        std::set<std::pair<int, int>> apps;
        
        for (auto i = nums.begin(); i < nums.end(); i++)
        {
            std::pair<int, int> temp;
            temp.first = *i;
            temp.second = 1;

            // if this condition is true then it is in the set
            if (apps.find(temp) != apps.end())
            {
                return true;
            } else {
                apps.insert(temp);
            }
            
        }
        
        return false;
    }
};

int main() {
    std::vector<int> nums = {1, 2, 3, 1};
    Solution s;

    std::cout << s.containsDuplicate(nums) << std::endl;  

    return 0;
}
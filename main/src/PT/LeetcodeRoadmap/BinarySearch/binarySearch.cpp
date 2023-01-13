#include <iostream>
#include <vector>

/*
    Given an array of integers nums which is sorted in ascending order, and an integer target, write a function to search target in nums. If target exists, 
    then return its index. Otherwise, return -1.

    You must write an algorithm with O(log n) runtime complexity.

    

    Example 1:

    Input: nums = [-1,0,3,5,9,12], target = 9
    Output: 4
    Explanation: 9 exists in nums and its index is 4
*/

class Solution {
public:
    int search(std::vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size()-1;
        int pos = -1;

        while (l <= r)
        {
            int mid = (l+(r-l))/2;
            if (nums[mid] == target)
            {
                pos = mid;
                break;
            } else if (nums[mid] > target)
            {
                r = mid-1;
            } else {
                l = mid+1;
            }
            
            
        }
        
        return pos;
    }
};

int main() {
    std::vector<int> nums = {-1, 0, 3, 5, 9, 12};
    int target = 9;
    Solution s;

    std::cout << s.search(nums, target) << std::endl;

    return 0;
}
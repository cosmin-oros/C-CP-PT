#include <iostream>
#include <algorithm>
#include <vector>

/*
    Given an array nums with n objects colored red, white, or blue, 
    sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

    We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

    You must solve this problem without using the library's sort function.

    

    Example 1:

    Input: nums = [2,0,2,1,1,0]
    Output: [0,0,1,1,2,2]

    Constraints:

    n == nums.length
    1 <= n <= 300
    nums[i] is either 0, 1, or 2.
*/

class Solution {
public:
    void sortColors(std::vector<int>& nums) {
        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n-i-1; j++)
            {
                if (nums[j] > nums[j+1])
                {
                    std::swap(nums[j], nums[j+1]);
                }
                
            }
            
        }
        
    }

    void printColors(std::vector<int>& nums) {
        for (auto i = nums.begin(); i < nums.end(); i++)
        {
            std::cout << *i << " ";
        }
        std::cout << "\n";
    }
};

int main() {
    std::vector<int> nums = {2, 0, 2, 1, 1, 0};
    Solution s;

    s.sortColors(nums);

    s.printColors(nums);

    return 0;
}
#include <iostream>
#include <vector>

/*
    Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.
    Note that you must do this in-place without making a copy of the array.

    Example 1:

    Input: nums = [0,1,0,3,12]
    Output: [1,3,12,0,0]
*/

class Solution {
public:
    void moveZeros(std::vector<int>& nums) {
        int len = nums.size();

        for (int i = 0; i < len; i++)
        {
            // if the number is 0 then we place it at the end and left shift the array
            if (!nums[i])
            {
                int temp = nums[i];
                // left shift
                for (int j = i; j < len; j++)
                {
                    nums[j] = nums[j+1];
                }

                // place the nr at the end
                nums[len-1] = temp;
                // we move the end to the left so that we don't place the next 0 on the same position
                len--;
                
            }
            
        }
        
    }

    void printZeros(std::vector<int>& nums) {
        for (auto i = nums.begin(); i < nums.end(); i++)
        {
            std::cout << *i << " ";
        }
        std::cout << "\n";
        
    }
};

int main() {
    Solution s;
    std::vector<int> nums = {0, 1, 0, 3, 12};

    s.moveZeros(nums);

    s.printZeros(nums);

    return 0;
}
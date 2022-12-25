#include <iostream>
#include <vector>

/*
    Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

    The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

    You must write an algorithm that runs in O(n) time and without using the division operation.

    Example 1:

    Input: nums = [1,2,3,4]
    Output: [24,12,8,6]
*/

class Solution {
public:
    std::vector<int> productExceptSelf(std::vector<int>& nums) {
        // base case
        if(nums.size() == 0 || nums.size() == 1) {
            return nums;
        }

        std::vector<int> prod(nums.size(),1);

        for(int i = 1; i < nums.size(); i++){
            prod[i] = prod[i-1]*nums[i-1];
        }

        int p = 1;

        for(int i = nums.size()-1; i >= 0;i--){
            prod[i] *=p;
            p *= nums[i];
        }
        
        return prod;
        
    }
};

int main() {
    std::vector<int> nums = {1, 2, 3, 4};
    Solution s;

    std::vector<int> answer = s.productExceptSelf(nums);

    for (auto i = answer.begin(); i < answer.end(); i++)
    {
        std::cout << *i << " ";
    }
    std::cout << std::endl;
    

    return 0;
}
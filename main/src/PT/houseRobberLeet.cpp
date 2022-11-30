#include <iostream>

#define LEN 5

/*
    You are a professional robber planning to rob houses along a street. 
    Each house has a certain amount of money stashed, the only constraint stopping you from robbing
    each of them is that adjacent houses have security systems connected and it will automatically 
    contact the police if two adjacent houses were broken into on the same night.
    Given an integer array nums representing the amount of money of each house, 
    return the maximum amount of money you can rob tonight without alerting the police.

 

    Example 1:

    Input: nums = [1,2,3,1]
    Output: 4
    Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
    Total amount you can rob = 1 + 3 = 4.

    Constraints:

    1 <= nums.length <= 100
    0 <= nums[i] <= 400
*/

int findMaxAmount(int nums[]) {
    int max1 = 0;
    int max2 = 0;

    // check the constraints
    if (LEN < 1 || LEN > 100)
    {
        return 0;
    }
    
    for (int i = 0; i < LEN; i++)
    {
        if (nums[i] < 0 || nums[i] > 400)
        {
            return 0;
        }
        
    }

    for (int i = 0; i < LEN; i += 2)
    {
        max1 += nums[i];
    }
    
    for (int i = 1; i < LEN; i += 2)
    {
        max2 += nums[i];
    }
    
    return (max1 > max2) ? max1 : max2;

}

int main() {
    // how much money each house has
    int nums[LEN] = {2, 7, 9, 3, 1};

    int maxAmount = findMaxAmount(nums);

    std::cout << "The maximum amount of money that you can rob is: " << maxAmount << "\n";

    return 0;
}
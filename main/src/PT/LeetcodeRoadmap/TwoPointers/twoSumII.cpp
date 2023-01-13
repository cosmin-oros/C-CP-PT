#include <iostream>
#include <vector>

/*
    Given a 1-indexed array of integers numbers that is already sorted in non-decreasing order, find two numbers such that they add up to a specific target number. 
    Let these two numbers be numbers[index1] and numbers[index2] where 1 <= index1 < index2 <= numbers.length.

    Return the indices of the two numbers, index1 and index2, added by one as an integer array [index1, index2] of length 2.

    The tests are generated such that there is exactly one solution. You may not use the same element twice.

    Your solution must use only constant extra space.

    

    Example 1:

    Input: numbers = [2,7,11,15], target = 9
    Output: [1,2]
    Explanation: The sum of 2 and 7 is 9. Therefore, index1 = 1, index2 = 2. We return [1, 2].
*/

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& numbers, int target) {
        int left = 0;
        int right = numbers.size()-1;
        std::vector<int> output;

        while (left < right)
        {
            if (numbers[left] + numbers[right] == target)
            {
                output.push_back(left+1);
                output.push_back(right+1);
            }
            // because they are sorted in non descending order if the sum is smaller then the target then we have to move the left pointer
            // otherwise move the right pointer
            else if (numbers[left] + numbers[right] < target)
            {
                left++;
            } else {
                right++;
            }
            
        }
        
        return output;
    }
};

int main() {
    std::vector<int> numbers = {2, 7, 11, 15};
    int target = 9;
    Solution s;

    std::vector<int> output = s.twoSum(numbers, target);

    for (auto i = output.begin(); i < output.end(); i++)
    {
        std::cout << *i << " ";
    }
    std::cout << std::endl;

    return 0;
}
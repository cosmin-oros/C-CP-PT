#include <iostream>
#include <vector>

/*
    Given an integer array nums of unique elements, return all possible 
    subsets
    (the power set).

    The solution set must not contain duplicate subsets. Return the solution in any order.

    

    Example 1:

    Input: nums = [1,2,3]
    Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
*/

class Solution {
public:
    std::vector<std::vector<int>> ans;

    void backtrack(std::vector<int>& arr, int start, std::vector<int>& temp){
        ans.push_back(temp);

        for(int i = start; i < arr.size(); i++){
            temp.push_back(arr[i]);
            backtrack(arr, i+1, temp);
            temp.pop_back();
        }
    }
    std::vector<std::vector<int>> subsets(std::vector<int>& arr) {
        int n = arr.size();
        std::vector<int> temp;
        backtrack(arr, 0, temp);
        return ans;
    }
};

int main() {
    std::vector<int> nums = {1, 2, 3};
    Solution s;

    std::vector<std::vector<int>> subsets = s.subsets(nums);

    for (int i = 0; i < subsets.size(); i++)
    {
        for (int j = 0; j < subsets.at(i).size(); j++)
        {
            std::cout << subsets[i][j] << " ";
        }
        std::cout << std::endl;
        
    }
    

    return 0;
}
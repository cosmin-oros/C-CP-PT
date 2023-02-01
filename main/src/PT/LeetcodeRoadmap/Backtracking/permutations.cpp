#include <iostream>
#include <vector>

/*
    Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

    Example 1:

    Input: nums = [1,2,3]
    Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
*/

class Solution {
public:
    std::vector<std::vector<int>> permute(std::vector<int>& nums) {
        std::vector<std::vector<int>> res;
        std::vector<int> s;

        backtrack(res, nums, s);
        return res;
    }

    void backtrack(std::vector<std::vector<int>>& res, std::vector<int> nums, std::vector<int> s) {
        if (!nums.size())
        {
            res.push_back(s);
            return;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            std::vector<int> n, m;

            std::copy(nums.begin(), nums.end(), back_inserter(n));
            std::copy(s.begin(), s.end(), back_inserter(m));
            n.erase(n.begin()+i);
            m.push_back(nums[i]);
            backtrack(res, n, s);
        }
        
        
    }
};

int main() {
    std::vector<int> nums = {1, 2, 3};
    Solution s;

    std::vector<std::vector<int>> perm = s.permute(nums);

    for (int i = 0; i < perm.size(); i++)
    {
        for (int j = 0; j < perm[i].size(); j++)
        {
            std::cout << perm[i][j];
        }
        
    }
    

    return 0;
}
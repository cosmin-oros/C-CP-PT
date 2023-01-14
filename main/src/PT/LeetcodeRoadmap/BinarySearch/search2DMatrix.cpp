#include <iostream>
#include <vector>

/*
    You are given an m x n integer matrix matrix with the following two properties:

    Each row is sorted in non-decreasing order.
    The first integer of each row is greater than the last integer of the previous row.
    Given an integer target, return true if target is in matrix or false otherwise.

    You must write a solution in O(log(m * n)) time complexity.

    

    Example 1:


    Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
    Output: true
*/

class Solution {
public:
    bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        if (rows == 1 && cols == 1)
        {
            return matrix[0][0] == target;
        }

        int l = 0, r = rows*cols;

        while (r >= l)
        {
            int mid = (r+l)/2;

            if (mid >= rows*cols)
            {
                return false;
            } else if (matrix[mid/cols][mid%cols] == target) {
                return true;
            } else if (matrix[mid/cols][mid%cols] > target) {
                r = mid-1;
            } else {
                l = mid+1;
            }
            
        }
        
        return false;
    }
};

int main() {
    std::vector<std::vector<int>> matrix = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}
    };
    int target = 3;
    Solution s;

    std::cout << s.searchMatrix(matrix, target) << std::endl;

    return 0;
}
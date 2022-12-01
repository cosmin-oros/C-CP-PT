#include <iostream>
#include <vector>
#include <algorithm>

#define SIZE 4

/*
    Given an array of intervals where intervals[i] = [starti, endi],
     merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.

    Example 1:

    Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
    Output: [[1,6],[8,10],[15,18]]
    Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].
*/

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
std::vector<std::vector<int>> merge(std::vector<std::vector<int>>& intervals) {
    int n = intervals.size();
    std::vector<std::vector<int>> sol;
     
    std::sort(intervals.begin(), intervals.end());

    for(int i = 0; i < n; i++){
        int maxEnd = intervals[i][1];
        int j = i+1;

        while((j < n) && (intervals[j][0] <= maxEnd)){
            maxEnd = std::max(maxEnd, intervals[j][1]);
            j++;
        }
        sol.push_back({intervals[i][0], maxEnd});
        i=j-1;
    }   
    return sol;
}

void printVector(std::vector<std::vector<int>>& intervals) {
    for (int i = 0; i < intervals.size(); i++)
    {
        for (int j = 0; j < intervals[i].size(); j++)
        {
            std::cout << intervals[i][j] << " ";
        }
        std::cout << "\n";
        
    }
    
}

int main() {
    std::vector<std::vector<int>> intervals = {
        {1, 3},     // 1 -> starti, 3 -> endi
        {2, 6},
        {8, 10},
        {15, 18}
    };

    std::vector<std::vector<int>> merged = merge(intervals);

    printVector(merged);

    return 0;
}
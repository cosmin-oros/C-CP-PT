#include <iostream>
#include <vector>
#include <unordered_map>

/*
    You are given n points in the plane that are all distinct, where points[i] = [xi, yi]. A boomerang is a tuple of points (i, j, k) 
    such that the distance between i and j equals the distance between i and k (the order of the tuple matters).
    Return the number of boomerangs.

    Example 1:

    Input: points = [[0,0],[1,0],[2,0]]
    Output: 2
    Explanation: The two boomerangs are [[1,0],[0,0],[2,0]] and [[1,0],[2,0],[0,0]].
*/

class Solution {
public:
    int numberOfBoomerangs(std::vector<std::pair<int, int>>& points) {
        int res = 0;
    
    // iterate over all the points
    for (int i = 0; i < points.size(); i++) {
        
        std::unordered_map<long, int> group(points.size());
        
        // iterate over all points other than points[i]
        for (int j = 0; j < points.size(); ++j) {
            
            if (j == i) { 
                continue;
            }
            
            int dy = points[i].second - points[j].second;
            int dx = points[i].first - points[j].first;
            
            // compute squared euclidean distance from points[i]
            int key = dy * dy;
            key += dx * dx;
            
            // accumulate # of such "j"s that are "key" distance from "i"
            ++group[key];
        }
        
        for (auto& p : group) {
            if (p.second > 1) {
                res += p.second * (p.second - 1);
            }
        }
    }
    
    return res;
    }
};

int main() {
    std::vector<std::pair<int, int>> points = {
        {0, 0},
        {1, 0},
        {2, 0}
    };
    Solution s;

    std::cout << s.numberOfBoomerangs(points) << std::endl;

    return 0;
}
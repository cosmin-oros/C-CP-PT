#include <iostream>
#include <vector>
#include <unordered_map>

/*
    Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

    Example 1:

    Input: nums = [1,1,1,2,2,3], k = 2
    Output: [1,2]
*/

class Solution {
public:
    std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
        std::unordered_map<int, int> m;
        std::unordered_map<int, std::vector<int>> m2;
        std::vector<int> rank, res;
        for (int v : nums) {
            m[v]++;
        }
        for (auto it = m.begin(); it != m.end(); it++) {
            if (m2.find(it->second) == m2.end()) {
                rank.push_back(it->second);
            }
            m2[it->second].push_back(it->first);
        }
        qSort(rank, 0, rank.size() - 1);
        for (int i = rank.size() - 1; k > 0; i--) {
            for (int v : m2[rank[i]]) {
                if (k == 0) {
                    break;
                }
                res.push_back(v);
                k--;
            }
        }
        return res;
    }
    void qSort(std::vector<int>& v, int left, int right) {
        if (left >= right) {
            return;
        }
        int p = left;
        std::swap(v[(left + right) / 2], v[right]);
        for (int i = left; i < right; i++) {
            if (v[i] < v[right]) {
                std::swap(v[i], v[p++]);
            }
        }
        std::swap(v[p], v[right]);
        qSort(v, left, p - 1);
        qSort(v, p + 1, right);
    } 
};

int main() {
    Solution s;
    std::vector<int> nums = {1, 1, 1, 2, 2, 3};
    int k = 2;

    std::vector<int> topK = s.topKFrequent(nums, k);

    for (auto i = topK.begin(); i < topK.end(); i++) {
        std::cout << *i << " ";
    }
    std::cout << std::endl;

    return 0;
}
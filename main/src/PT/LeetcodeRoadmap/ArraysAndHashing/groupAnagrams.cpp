#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

/*
    Given an array of strings strs, group the anagrams together. You can return the answer in any order.

    An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

    Example 1:

    Input: strs = ["eat","tea","tan","ate","nat","bat"]
    Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
*/

class Solution {
public:
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
        std::unordered_map<std::string, std::vector<std::string>> h;

        for (int i = 0; i < strs.size(); i++) {
            std::string temp = strs[i];
            std::sort(temp.begin(), temp.end());
            h[temp].push_back(strs[i]);
        }

        std::vector<std::vector<std::string>> ans;

        for (auto m: h) { 
            ans.push_back(m.second);
        }

        return ans;
    }
};

int main() {
    std::vector<std::string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    Solution s;

    std::vector<std::vector<std::string>> anagrams = s.groupAnagrams(strs);

    for (auto i: anagrams) {
        for (auto j: i) {
            std::cout << j << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
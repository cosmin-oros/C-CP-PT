#include <iostream>
#include <unordered_map>

/*
    Given two strings s and t, return true if t is an anagram of s, and false otherwise.

    An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

    Example 1:

    Input: s = "anagram", t = "nagaram"
    Output: true
*/

class Solution {
public:
    bool isAnagram(std::string s, std::string t) {
        if (s.length() != t.length())
        {
            return false;
        }

        std::unordered_map<char, int> apps;

        // if we add the appearance of a char from s and then subtract it from t then the nr of appearances of all chars from
        // s should be 0
        for (int i = 0; i < s.length(); i++)
        {
            apps[s[i]]++;
            apps[t[i]]--;
        }

        for (auto i: apps)
        {
            if (i.second)
            {
                return false;
            }
            
        }
        return true;
        
    }
};

int main() {
    Solution s;

    std::cout << s.isAnagram("anagram", "nagaram") << std::endl;
    
    return 0;
}
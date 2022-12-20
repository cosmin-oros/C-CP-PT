#include <iostream>

/*
    Given two strings s and t, return true if s is a subsequence of t, or false otherwise.

    A subsequence of a string is a new string that is formed from the original string by deleting some (can be none) of the
    characters without disturbing the relative positions of the remaining characters. (i.e., "ace" is a subsequence of "abcde" while "aec" is not).

    Example 1:

    Input: s = "abc", t = "ahbgdc"
    Output: true
*/

class Solution {
public:
    bool isSubsequence(std::string s, std::string t) {
        int i = 0;

        // removing characters that s doesn't contain
        while ((s.size() != t.size()) || (i < s.size()))
        {
            if (!contains(s, t.at(i)))
            {
                t.erase(i, i);
            }

            i++;
            std::cout << t << "\n";
        }

        if (i != s.size()-1)
        {
            for (int j = 0; j < t.size(); j++)
            {
                if (t.at(j) != s.at(j))
                {
                    t.erase(j, j);
                    j--;
                }
                
            }
            
        }
        
        
        if (s == t)
        {
            return true;
        }
        return false;
        
    }

    bool contains(std::string s, char c) {
        for (int i = 0; i < s.size(); i++)
        {
            if (s.at(i) == c)
            {
                return true;
            }
            
        }
        return false;
        
    }
};

int main() {
    Solution sol;
    std::string s = "abc";
    std::string t = "ahbgdc";

    if (sol.isSubsequence(s, t))
    {
        std::cout << "The string " << s << " is a subsequence of the string " << t << "\n";
    } else {
        std::cout << "The string " << s << " is not a subsequence of the string " << t << "\n";
    }
    

    return 0;
}
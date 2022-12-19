#include <iostream>
#include <unordered_set>

/*
    Given a string s, reverse only all the vowels in the string and return it.

    The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in both lower and upper cases, more than once. 

    Example 1:

    Input: s = "hello"
    Output: "holle"
*/

class Solution {
public:
    std::unordered_set<char> const c_vowels = {'a', 'A', 'e', 'E', 'i', 'I', 'o', 'O', 'u', 'U'};

    std::string reverseVowels(std::string s) {
        int l = 0, r = s.size() - 1;
        
        while (true) {
            while (l < r && c_vowels.find(s[l]) == c_vowels.end()) {
                l++;
            }

            while (r > l && c_vowels.find(s[r]) == c_vowels.end()) {
                r--;
            }

            if (l >= r) {
                break;
            }

            std::swap(s[l], s[r]);
            l++;
            r--;
        }
        return s;
    }
};

int main() {
    Solution sol;
    std::string s = "hello";

    s = sol.reverseVowels(s);

    std::cout << s; 

    return 0;
}
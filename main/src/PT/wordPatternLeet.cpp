#include <iostream>
#include <string>
#include <unordered_map>

/*
    Given a pattern and a string s, find if s follows the same pattern.

    Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in s.

    Example 1:

    Input: pattern = "abba", s = "dog cat cat dog"
    Output: true
*/

bool followsPattern(const std::string& pattern, const std::string& s) {
    std::unordered_map<char, std::string> mapping;

    // Split the string into words
    std::string* words = new std::string[pattern.size()];
    int index = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == ' ') {
            index++;
        } else {
            words[index] += s[i];
        }
    }

    // Check if the pattern and words have the same length
    if (index + 1 != pattern.size()) {
        return false;
    }

    // Check if the pattern and words match
    for (int i = 0; i < pattern.size(); ++i) {
        if (mapping.count(pattern[i])) {
        // If the letter is already mapped to a word, check if the
        // current word is the same as the mapped word
        if (mapping[pattern[i]] != words[i]) {
            return false;
        }
        } else {
        // If the letter is not mapped to a word, check if the
        // current word has been mapped to another letter
        for (const auto& [letter, word] : mapping) {
            if (word == words[i]) {
            return false;
            }
        }

        // If the current word is not mapped to another letter,
        // map it to the current letter
        mapping[pattern[i]] = words[i];
        }
    }

    return true;
}

int main() {
    std::string pattern = "abba", s = "dog cat cat dog";

    if (followsPattern(pattern, s)) {
        std::cout << "The string follows the pattern." << std::endl;
    } else {
        std::cout << "The string does not follow the pattern." << std::endl;
    }

    return 0;

}

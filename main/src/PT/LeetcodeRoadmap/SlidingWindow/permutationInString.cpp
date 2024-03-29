#include <iostream>
#include <unordered_map>

/*
    Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.

    In other words, return true if one of s1's permutations is the substring of s2.

    

    Example 1:

    Input: s1 = "ab", s2 = "eidbaooo"
    Output: true
    Explanation: s2 contains one permutation of s1 ("ba").
    Example 2:

    Input: s1 = "ab", s2 = "eidboaoo"
    Output: false
*/

class Solution {
public:
    bool checkInclusion(std::string s1, std::string s2) {
        std::unordered_map<char, int> mp;    
        for(auto it : s1){
            mp[it]++;
        }

        int count = mp.size();         
        int i = 0, j = 0;
        int k = s1.size();          
          
        while(j < s2.size()){
            if(mp.find(s2[j]) != mp.end()){      
                mp[s2[j]]--;
                if(mp[s2[j]] == 0){     
                    count--;
                }
            }
            if(j-i+1 < k){
                j++;
            }
            else if(j-i+1 == k){
				if(count == 0){    
					return true;  
				}
                if(mp.find(s2[i]) != mp.end()){  
                    mp[s2[i]]++;
                    if(mp[s2[i]] == 1){
                        count++;
                    }
                }
                i++;
                j++;
            }
        }
        return false;
    }
};

int main() {
    std::string s1 = "ab";
    std::string s2 = "eidbaooo";
    Solution s;

    std::cout << s.checkInclusion(s1, s2) << std::endl;

    return 0;
}
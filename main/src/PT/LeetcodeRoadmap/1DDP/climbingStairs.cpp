#include <iostream>
#include <vector>

/*
    You are climbing a staircase. It takes n steps to reach the top.

    Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

    

    Example 1:

    Input: n = 2
    Output: 2
    Explanation: There are two ways to climb to the top.
    1. 1 step + 1 step
    2. 2 steps
*/

class Solution {
public:
    int solve(int n, std::vector<int> &dp){
        //base case
        if(n <= 2) {
            return n;
        }
        
        if(dp[n] != -1) {
            return dp[n];
        } 
        
        dp[n] = solve(n-1, dp) + solve(n-2, dp);

        return dp[n];
    }
    int climbStairs(int n) {
        if(n <= 2) {
            return n;
        }
        std::vector<int> dp(n+1);

        for(int i = 0; i <= n; i++) {
            dp[i] =- 1;
        }
        
        return solve(n, dp);
    }
};

int main() {
    Solution s;
    int n = 2;

    std::cout << s.climbStairs(n) << std::endl;

    return 0;
}
#include <iostream>

using namespace std;

// Returns count of ways n people
// can remain single or paired up.
int countFriendsPairings(int n)
{
    int* dp = new int[n+1];
 
    // Filling dp[] in bottom-up manner using
    // recursive formula explained above.
    for (int i = 0; i <= n; i++) {
        if (i <= 2){
            dp[i] = i;
        }else{
            dp[i] = dp[i - 1] + (i - 1) * dp[i - 2];
        }
    }
 
    return dp[n];
}

int main(){
    cout << countFriendsPairings(4) << endl;

    return 0;
}
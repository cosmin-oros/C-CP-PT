#include <iostream>

using namespace std;

void printGolomb(int n)
{
    int* dp = new int[n+1];
 
    // base cases
    dp[1] = 1;
    cout << dp[1] << " ";
 
    // Finding and printing first
    // n terms of Golomb Sequence.
    for (int i = 2; i <= n; i++)
    {
        dp[i] = 1 + dp[i - dp[dp[i - 1]]];
        cout << dp[i] << " ";
    }
}

int main(){
    printGolomb(7);
    
    return 0;
}
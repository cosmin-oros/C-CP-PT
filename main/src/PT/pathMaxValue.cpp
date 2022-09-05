#include <iostream>

using namespace std;

const int M = 100;

double maxAverageOfPath(int cost[M][M], int N)
{
    int** dp = (int**)malloc(N*sizeof(int*));
    dp[0][0] = cost[0][0];
 
    /* Initialize first column of total cost(dp) array */
    for (int i = 1; i < N; i++){
        dp[i][0] = dp[i-1][0] + cost[i][0];
    }
 
    /* Initialize first row of dp array */
    for (int j = 1; j < N; j++){
        dp[0][j] = dp[0][j-1] + cost[0][j];
    }
 
    /* Construct rest of the dp array */
    for (int i = 1; i < N; i++){
        for (int j = 1; j <= N; j++){
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + cost[i][j];
        }
    }

 
    // divide maximum sum by constant path
    // length : (2N - 1) for getting average
    return (double)dp[N-1][N-1] / (2*N-1);

    free(dp);
}

int main(){
    int cost[M][M] = { 
        {1, 2, 3},
        {6, 5, 4},
        {7, 3, 9}
    };

    cout << maxAverageOfPath(cost, 3);

    return 0;
}
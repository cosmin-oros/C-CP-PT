#include <stdio.h>
#include <stdlib.h>

/*
3. Revisiting the coin make change problem, use dynamic programming to count in how many ways can a certain amount of money
be expressed in terms of a given set of coin values. The order of the coins is not important. Use a 2D array to store the partial solutions.
*/

#define N 3
int coins[N] = {1, 5, 10};

void coinCombinations(int money){
    if (money < 0)
    {
        printf("Invalid amount of money\n");
        exit(-1);
    }
    if (!money)
    {
        printf("Change: 0\n");
        exit(-1);
    }
    
    int largestUsableCoinIndex;
    for (int i = N; i >= 0; i--)
    {
        if (money >= coins[i])
        {
            largestUsableCoinIndex = i;
            break;
        }
        
    }
    
    int** change = (int**)calloc(money,sizeof(int*));
    for (int i = 0; i < N; i++)
    {
        change[i] = (int*)calloc(N,sizeof(int));
    }
    
    int possiblePath = 1;

    while (possiblePath)
    {
        int j = 0;

        for (int k = largestUsableCoinIndex; k >= 0; k--)
        {
            for (int i = 0; i < money; i++)
            {
                int m = money;
                if (i == 0)
                {
                    while (m-coins[k]>=0 && checkMoney(change[i][j],i,j,change,money))
                    {
                        change[i][j]++;
                        m-=coins[k];
                    }
                    
                }else{
                    while (m-coins[k]>=0 && checkValid(change[i][j],i,j,change,money) && checkMoney(change[i][j],i,j,change,money))
                    {
                        change[i][j]++;
                        m-=coins[k];
                    }
                }
                
            
            }
            j++;   
        }
        
    }
    
    printSol(change,money);
    free(change);
}

int checkMoney(int c,int i,int j,int** change,int money){
    int m = money;
    for (int k = 0; k < N; k++)
    {
        m -= change[i][k]*coins[N-k];
    }
    if (m >= 0)
    {
        return 1;
    }
    return 0;
    
}

int checkValid(int c,int i,int j,int** change,int money){
    if(c == 0){
        return 1;
    }

    for (int k = 0; k < money; k++)
    {
        if (change[k][j] == c && k!=i)
        {
            return 0;
        }
        
    }
    return 1;
    
}

void printSol(int** change,int money){
    printf("\n--------------------------------\n");
    for (int i = 0; i < money; i++)
    {
        int m = 0;
        for (int j = 0; j < N; j++)
        {
            m+=change[i][j]*coins[N-j];
        }
        if (m == money)
        {
            for (int j = 0; j < N; j++)
            {
                if (change[i][j])
                {
                    printf("%d %d coins ",change[i][j],coins[N-j]);
                }
            
            }
            printf("\n");
        }
        
    }
    printf("\n");
    
}

int main(){
    int money;

    printf("Enter the amount of money that you want change for:\n");
    scanf("%d",&money);

    coinCombinations(money);
    return 0;
}
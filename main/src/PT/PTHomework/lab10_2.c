#include <stdio.h>

/*
    Use Greedy to determine the minimum number of coins to give
    while making change. Your currency supports coins with values 1,
    5, 10, 20. The change value is given as input. Print the solution on
    the screen.
*/

int coins[] = {1, 5, 10, 20};   //the coins available (infinite supply)
#define N 4     //the number of different coin types

int change[N] = {0};    //initialized as 0 coins for each type of coin

void findMinChange(int c){
    //only check if you have coins given
    if (c>0)
    {    
        for (int i = N-1; i >= 0 ; i--)
        {
            /*  substract the value of the respective type of coin
                and add the number of coins needed for the change
                as long as the value remaining is bigger or equal 
                to that of the respective coin 
            */
            while (c >= coins[i])
            {
                c -= coins[i];
                change[i]++;
            }
        
        }
    }
    
}

void printMinChange(){
    int k=0;    //key control to check if you have coins given
    for (int i = 0; i < N; i++)
    {
        k += change[i];
        if (k)
        {
            break;  //if we find that we have coins given we break out of the loop
        }
        
    }
    if (k>0)
    {
        printf("You get: ");

        for (int i = N-1; i >= 0; i--)
        {
            //only print if the number of coins is non-zero
            if (change[i])
            {
                printf("%d C%d ",change[i],coins[i]);
            }
        }
    }else{
        printf("You didn't give a valid number of coins");
    }
    printf("\n");
}

int main(){
    int c;  //the coins given as input
    
    printf("Enter your coins:");
    scanf("%d",&c);
    printf("\n");

    //find the minimum change for the number of coins given as input
    findMinChange(c);

    //print the minimum amount of coins for change
    printMinChange();
    return 0;
}
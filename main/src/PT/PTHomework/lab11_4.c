#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
4. Given an amount of money and a set of N coins and their values,
print all possible ways to make the change.
*/

#define N 5
//the array of coins
int coins[N] = {1, 2, 5, 10, 25};
//how many combinations
int count = 0;

//function for finding all the coin change combinations
int coinCombinations(int money){
    int possiblePath;
    if (money < 0)
    {
        return -1;    
    }
    if (money == 0)
    {
        count++;
        printf("%d combinations \n Change: 0\n",count);
    }
    
    //allocate money times of spaces because the longest array could be money * 1 coins
    int* change = calloc(money,sizeof(int));
    if (!change)
    {
        printf("Couldn't allocate memory\n");
        return -1;
    }
    
    for (int i = N-1; i >= 0; i--)
    {

        //find the biggest coin for the change
        while (coins[i]>money)
        {
            i--;
        }
        
        possiblePath = 1;
        while (possiblePath)
        {
            int end = 0;
            int m = money;
            int k = 0;
            int j = i;
            change[0] = coins[i];
            m -= coins[i];

            while (m>0 && j>=0)
            {
                if ((m-coins[j])>=0)
                {
                    change[k++] = coins[j];
                    m -= coins[j];
                }else{
                    j--;
                }
                
            }
            
            //check if we reached the last solution for that branch
            for (int p = 1; change[p]; p++)
            {
                if (change[p] == coins[0])
                {
                    end = 1;
                }else{
                    end = 0;
                }
                
            }    

            //reset all elements of the array to 0
            printSol(change);
            memset(change,0,money);  

            if (end)
            {
                possiblePath = 0;
            }
        }
     
    }
    
    free(change);
}

void printSol(int* change){
    printf("\n--------------------------------\n");
    for (int i = 0; change[i]; i++)
    {
        printf("%d ",change[i]);
    }
    printf("\n");
    
}

int main(){
    int money;
    printf("Enter the amount of money: ");
    scanf("%d",&money);
    printf("\n");

    coinCombinations(money);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

/*
    Generate all 10 digit telephone nrs which start with 0721 and have 3 distinct even digits
*/

int s[100] = {0};

int valid(int k, int* s){
    if (k > 9)
    {
        return 0;
    }

    if (k > 3)
    {
        for (int i = 4; i < k; i++)
        {
            if (s[i] == s[k] && s[i]%2 == 0)
            {
                return 0;
            }
            
        }
        
    }
    
    return 1;
}

int solution(int k, int* s){
    int even = 0;

    if (k == 9)
    {
        for (int i = 4; i <= k; i++)
        {
            if (!(s[i]%2))
            {
                even++;
            }
        }

        //if we have 3 distinct even digits we return true else we return false
        return (even == 3) ? 1 : 0;
    }

    return 0;
}

void printSolution(int* s){
    //print the prefix
    for (int i = 0; i < 4; i++)
    {
        printf("%d",s[i]);
    }
    printf(" ");

    //print the other digits
    for (int i = 4; i < 10; i++)
    {
        printf("%d",s[i]);
    }
    printf(";\n");
    
}

void backtrack(int* s, int k){
    //init the prefix
    s[0] = 0;
    s[1] = 7;
    s[2] = 2;
    s[3] = 1;

    for (int i = 0; i < 10; i++)
    {
        if (k > 3)
        {
            s[k] = i;
        }

        if (valid(k,s))
        {
            if (solution(k,s))
            {
                printSolution(s);
            }else{
                backtrack(s,k+1);
            }
            
        }
        
        
    }
    
}

int main(){
    backtrack(s,4);

    return 0;
}
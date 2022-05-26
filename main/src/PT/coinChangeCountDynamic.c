#include <stdio.h>

int count(int* s, int m, int n){
    //if n is 0 there is 0 solution
    if (!n)
    {
        return 1;
    }
    if (n < 0)  //if n is less then 0 then there is no solution
    {
        return 0;
    }
    if (m <= 0 && n >= 1)   //if there are no coins and the value exists then there is no solution
    {
        return 0;
    }
    
    return count(s,m-1,n) + count(s,m,n-s[m-1]);
    
}

int main(){
    //coins available
    int arr[] = {1,2,3};
    int size = 3;
    //the value that we want the number of coin changes for
    int value = 4;
    printf("%d\n",count(arr,size,value));
    return 0;
}
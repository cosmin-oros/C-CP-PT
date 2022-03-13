#include <stdio.h>

/*
Write a program to store the first N prime numbers into a vector
array. N is given as input from the keyboard. Write a function to
test, using binary search, if a given number X is present or not into
the array of prime numbers. You should test if X is prime before
searching the array.
*/

#define N 10

int checkPrime(int i){
    for (int j = 0; j < i/2; j++)
    {
        if (i%j==0)
        {
            return 0;
        }
        
    }
    return 1;
    
}

void fillPrimes(int primes[N]){
    int n=N;
    int k=-1;
    for (int i = 2; n; i++,n--)
    {
        if (checkPrime(i))
        {
            primes[k++]=i;
        }
        
    }
    
    
}

int main(){
    int primes[N];
    fillPrimes(primes);
    for (int i = 0; i < N; i++)
    {
        printf("%d ",primes[i]);
    }
    
    return 0;
}
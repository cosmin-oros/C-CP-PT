#include <stdio.h>

#define N 100

int f[N] = {0};

int fib(int n)
{
    unsigned int i;
    unsigned int k;

    //skip over the fib elements that were already computed
    for (k = 2; k < n && f[k]; k++)
    {
        ;
    }
    
    //compute the fib elements that remain
    if (n > k)
    {
        for (i = k; i <= n; i++)
        {
            f[i] = f[i-1] + f[i-2];   
        }
        
    }
    

    return (unsigned long int) f[n];
}

int main(){
    f[0] = 0;
    f[1] = 1;

    printf("fib(10) = %lu\n",fib(10));
    printf("fib(3) = %lu\n",fib(3));
    printf("fib(5) = %lu\n",fib(5));
    printf("fib(7) = %lu\n",fib(7));

    return 0;
}
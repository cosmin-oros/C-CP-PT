#include <stdio.h>
#include <stdlib.h>

unsigned long int fib(unsigned long int n){
    long int* f = malloc((n+1)*sizeof(long int));
    if (!f)
    {
        printf("Couldn't allocate mem\n");
        exit(-1);
    }
    
    unsigned int i;
    f[0] = 0;
    f[1] = 1;
    for (i = 2; i <= n; i++)
    {
        f[i] = -1;
    }
    
    if (n > 2)
    {
        for (i = 2; i <= n; i++)
        {
            if (f[i]<0)
            {
                f[i] = f[i-1] + f[i-2];
            }
            
        }
        
    }
    

    return (unsigned long int) f[n];
    free(f);
}

int main(void){
    printf("fib(10) = %lu\n",fib(10));
    printf("fib(3) = %lu\n",fib(3));
    printf("fib(5) = %lu\n",fib(5));
    printf("fib(7) = %lu\n",fib(7));

    return 0;
}
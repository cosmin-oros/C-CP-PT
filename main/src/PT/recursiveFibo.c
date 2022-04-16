#include <stdio.h>

int recursive_fib(int n){
    if (n<=0)
    {
        return 0;
    }
    if (n==1)
    {
        return 1;
    }
    if (n>1)
    {
        return (recursive_fib(n-1) + recursive_fib(n-2));
    }
}

int main(){
    printf("%d\n",recursive_fib(5));
    return 0;
}
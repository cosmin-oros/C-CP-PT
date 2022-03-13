#include <stdio.h>

typedef unsigned long long ull;

ull nth_fib(int n){
    ull n1=0;
    ull n2=1;
    ull a;
    while(n-2){
        a=n1;
        n1=n2;
        n2=a+n1;
        n--;
    }
    return n2;
}

int main(){
    ull n=nth_fib(10);
    printf("%llu\n",n);
    return 0;
}
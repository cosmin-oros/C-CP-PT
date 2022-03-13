#include <stdio.h>

/*
1. Golden ratio The ratio between two consecutive Fibonacci numbers rn = Fn+1/Fn converges to a number called the golden ratio.
Write a function that computes this limit, stopping when the difference between two successive approximations is lower than 1e-6. 
How many approximations of the ratio are computed for this precision? Avoid wasteful recomputations of Fibonacci numbers,
 and the same approach to write a recursive function that computes Fn efficiently.
*/

double fibo(){
    static int first=1,second=1;
    int sum;                        // 1 1 2 3 5 8 ...
    sum=first+second;
    first=second;
    second=sum;
    return 1.0*second/first;
}
double golden(){
    int k=1;
    double r1=1.0,r2;
    r2=fibo();
    k++;
    while((r2-r1>0.000001) || (r1-r2>0.000001)){
        r1=r2;
        r2=fibo();
        k++;
    }
    return r2;
}
int main(){
    printf("%lf\n",golden());
    return 0;
}
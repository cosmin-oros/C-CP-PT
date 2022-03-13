#include <stdio.h>

typedef unsigned long long int ull;

ull divisorsSum(ull n){
    ull s=0;
    for (ull i = 2; i <= n/2; i++)
    {
        if (n%i==0)
        {
            s+=i;
        }
        
    }
    return s;
    
}

ull csod(const ull n){
    ull sum = 0;
    for (ull i = 1; i <= n; i++)
    {
        sum+=divisorsSum(i);
    }
    return sum;
    
}

int main(){
    printf("%llu\n",csod(10000));
    return 0;
}
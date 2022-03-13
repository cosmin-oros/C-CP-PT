#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stddef.h>
//Problem 1
int swapLMD(unsigned n){
    int ls,a,ms;
    ls=n%10; //the least significant
    n=n/10;
    a=n%10;
    n=n/10;
    ms=n%10; //the most significant
    return(ls*100+a*10+ms);
}

int main(){
    unsigned number;
    scanf("%d",&number); //we receive input (the three digit number)
    printf("%d\n",swapLMD(number));
    return 0;
}


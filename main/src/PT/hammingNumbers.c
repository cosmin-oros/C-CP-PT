#include <stdio.h>

long long int hamber(unsigned n){
    if(!n){
        return NULL;
    }
    if(n==1){
        return 1;
    }
    //...
}

int main(){
    long long int a = hamber(5);
    printf("%lld\n",a);
}
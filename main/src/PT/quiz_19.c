#include <stdio.h>

unsigned f(unsigned n){
    int s=-1;
    while(n){
        if(n%10>s){
            s=n%10;
        }
        else{
            s=11;
        }
        n/=10;
    }
    return s;
}

int main(){
    unsigned a=f(9876);
    printf("%u\n",a);
    return 0;
}
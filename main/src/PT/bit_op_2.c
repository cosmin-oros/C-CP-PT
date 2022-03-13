#include <stdio.h>

unsigned cons_bits(unsigned n){
    unsigned contor=1;
    unsigned size=sizeof(n)*8;
    for(int i=0;i<size;i++){
        unsigned a=n&(1<<i);
        unsigned b=n&(1<<(i+1));
        if((a<<1)!=(b<<1)){
            contor++;
        }
    }
    return contor;
}

int main(){
    unsigned n;
    scanf("%d",&n);
    printf("%d\n",cons_bits(n));

    return 0;
}
#include <stdio.h>

int geom_seq(int n,int q){
    if(n<=1){
        return 1;
    }
    else{
        return geom_seq(n/q,q)+n;
    }
}

int main(){
    printf("%d\n",geom_seq(9,3));
    return 0;
}
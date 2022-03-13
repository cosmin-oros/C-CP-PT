#include <stdio.h>
//a)
float series(float n){
    if(n==1){
        return 1;
    }
    else{
        return series(n-1)+(1/(n*n));
    }
}

int main(){
    printf("%f\n",series(3));
    return 0;
}
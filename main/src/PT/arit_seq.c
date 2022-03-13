#include <stdio.h>

int arit_seq(int n,int r){
    if(n<=0){
        return 0;
    }
    else if(n==1){
        return 1;
    }
    else{
        return arit_seq(n-r,r)+n;
    }
}

int main(){

    printf("%d\n",arit_seq(8,3));
    return 0;
}
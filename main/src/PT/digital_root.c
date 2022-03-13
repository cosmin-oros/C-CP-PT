#include <stdio.h>

int digital_root(int n){
    int a;
    a=n;
    while(a>9){
        n=a;
        a=0;
        while(n){
            a+=n%10;
            n/=10;
        }
    }
    return a;
}

int main(){
    printf("%d",digital_root(132189));
    return 0;
}
#include <stdio.h>

int most_sign(int n){
    return n<10 ? n : most_sign(n/10);
}

int main(){
    printf("%d\n",most_sign(54321));

    return 0;
}
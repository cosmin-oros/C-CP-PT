#include <stdio.h>

int main(){
    long i,k=0; // i=5 (0101) k=3 (0011)
    printf("Enter two integers:\n");
    scanf("%ld%ld",&i,&k);
    printf("\n i=%ld before swapping and k=%ld before swapping\n",i,k);
    i=i^k;  // i= 0101 ^ 0011 = 0110
    k=i^k;  // k= 0110 ^ 0011 = 0101
    i=i^k;  // i= 0110 ^ 0101 = 0011
    printf("\n i=%ld after swapping and k=%ld after swapping\n",i,k);
    return 0;
}
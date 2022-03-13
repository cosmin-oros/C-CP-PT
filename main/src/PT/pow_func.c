#include <stdio.h>

double pwr(double n,double power){
    return power==0 ? 1 : n*pwr(n,power-1);
}

int main(void){
    printf("-2 raised to 3 = %.f\n",pwr(-2.0,3));
    return 0;
}
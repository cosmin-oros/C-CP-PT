/*
5. Prime factors Write a function that decomposes a number into prime factors, and prints out the result, in the form: 18=2*3^2.
 */
#include <stdio.h>

int prime(int i){
    int a=1;
    for (int j=2;j<=i/2;j++){
        if(i%j==0){
            a=0;
            break;
        }
    }
    return a;

}

void decompose(int nr){
    int power=0,is_first=1,contor=0;
    for (int i=2;i<=nr;i++){
        while(nr%i==0 && prime(i)){
            power++;
            nr=nr/i;
            contor=1;
        }
        if(is_first && contor){
            if(power>1){
                printf("%d^%d",i,power);
            }
            else{
                printf("%d",i);
            }
            is_first=0;
        }
        else if(is_first==0 && contor){
            printf("*");
            if(power>1){
                printf("%d^%d",i,power);
            }
            else{
                printf("%d",i);
            }
        }
        contor=0;
        power=0;
        
    }
    printf("\n");
}

int main(){
    decompose(18);
    return 0;
}
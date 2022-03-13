#include <stdio.h>

int func(int a,int b){
    printf("\na = %d\n",a);
    printf("\nb = %d\n",b);
}

int main(void){
    int(*fptr)(int,int);
    fptr=func;
    func(2,3);
    fptr(2,3);
    return 0;
}
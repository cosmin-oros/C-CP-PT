#include <stdio.h>

#define SIZE 10

int *getNEvenNumbers(int *numbers,const int n){
    for(int i=0;i<n;i++){
        *(numbers+i)=2*(i+1);
    }
    return numbers;
}

int main(){
    int evenNumbers[SIZE];
    getNEvenNumbers(evenNumbers,SIZE);
    printf("The first %d even numbers are:\n",SIZE);
    for(int i=0;i<SIZE;i++){
        printf("%d ",*(evenNumbers+i));
    }
    return 0;  
}
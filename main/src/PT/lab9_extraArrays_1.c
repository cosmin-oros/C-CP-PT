#include <stdio.h>
/*
Implement a function that receives an array together with its capacity and fills the array with 
all the negative numbers read from the input until 0 is entered. 
Fill as many values as possible, without overflowing the array.
*/

void printArray(int neg[], int CAP){
    int i=0;
    while(neg[i]!='\0'){
        printf("%d ",neg[i]);
        i++;
    }
}

void fillWithNegNumbers(int neg[], int cap){
    int modifCap=cap;
    int i=0,nr;
    scanf("%d",&nr);
    if(nr<0){
        neg[i]=nr;
    }
    while(modifCap && nr){
        scanf("%d",&nr);
        if(nr<0){
            neg[i++]=nr;
        }
        modifCap--;
    }
}

int main(){
    int neg[100],CAP=100;
    fillWithNegNumbers(neg,CAP);
    printArray(neg,CAP);
    return 0;
}
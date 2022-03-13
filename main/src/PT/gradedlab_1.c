#include <stdio.h>

unsigned sort_number(unsigned number){
    unsigned maxim=0,number2,maxPosition,number3=0,nr=0,position=0;
    while(number){
        number2=number;
        maxim=0;
        position=0;
        while(number2){
            position++;
            if(number2%10>maxim){
            maxim=number2%10;
            maxPosition=position;
        }
        number2=number2/10;
        }
        while((maxPosition-1)!=0){
            number3=number3*10+number%10;   //we get the digits until the maxdigit
            number=number/10;
            maxPosition--;
        }
        while(number3){
            number=number*10+number3%10;    //we get the new number eliminating the maxdigit
            number3=number3/10;
        }
        nr=nr*10+maxim;
    }
    return nr;
}

int main(){
    unsigned number=315;
    printf("%d",sort_number(number)); //we get the maximum number sorting the digits using the sort_number() function
    printf("\n");
    return 0;
}
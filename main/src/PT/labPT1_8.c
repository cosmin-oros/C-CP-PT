#include <stdio.h>
/*
8. A 10 digit ISBN uses the sum x10 = (∑
9
i=1
ixi) mod 11 where x10
is the check digit. If the last digit is 10, it is replaced with a roman
"X". For example ISBN 0521396549 has the check digit 9. Write a C
function to check the validity of ISBN-10.
*/

int isbn(char* tenDigNumber){
    int number[10];
    int s=0;
    for (int i = 0; tenDigNumber[i]!='\0'; i++)
    {
        if (i==9&&tenDigNumber[i]=='X')
        {
            number[i]=10;
        }
        else{
            number[i]=tenDigNumber[i]-'0';
        }
    }
    for (int i = 0; i < 9; i++)
    {
        s+=((i+1)*number[i]);
    }
    return ((s%11)==number[10])?1:0;
    
    
    
}

int main(){
    isbn("0521396549")==1?printf("True\n"):printf("False\n");
    return 0;
}
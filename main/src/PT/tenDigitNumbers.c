#include <stdio.h>
#include <stdlib.h>

/*
Generate all 10 digit telephone numbers which start with 0721 and for which the sum
of all digits is 38.The solutions are printed in a file called output.txt,one solution per line prefix space other digits , 
*/

void generateSol(FILE* fp){
    int sum = 10;   // 0+7+2+1 = 10

    //the sum of the rest of the digits has to be 28

    //the rest of the digits of the phone number
    int digits[6] = {0};    // 000000 -> sum has to be 28

    while (sumOfDigits(digits) != 28)
    {
        for (int i = 0; i<6 ; i++)
        {
            digits[i]++;

            if (sumOfDigits(digits) != 28)
            {
                break;
            }
            
        }
        
    }
    //first solution

    //test
    for (int i = 0; i < 6; i++)
    {
        printf("%d ",digits[i]);
    }
    
    
    
}

int sumOfDigits(int* digits){
    int s=0;
    for (int i = 0; i < 6; i++)
    {
        s += digits[i];
    }
    return s;
    
}

int main(){
    //output file
    FILE* fp = fopen("output.txt","w+");
    if (!fp)
    {
        printf("Couldn't open the file\n");
        return -1;
    }
    
    generateSol(fp);

    return 0;
}
#include <stdio.h>
#include <ctype.h>
/*
1. Write your own implementation of the strtod function: a) for floats in base 10; b) for hexadecimal floats.
*/

double strtod(char* s){
    double a=0;
    int point=0,digitsAfterPoint=0;
    for(int i=0;s!=NULL;i++){
        if(s[i]=='.'){
            point=1;
        }
        else if(isdigit(s[i])){
            a*=10+s[i];
            if(point){
                digitsAfterPoint++;
            }
        }
        
    }
    while(digitsAfterPoint){
        a/=10;
        digitsAfterPoint--;
    }
    return a;
}

int main(){
    char* s="12.35DA";
    printf("%f",strtod(s));
    return 0;
}
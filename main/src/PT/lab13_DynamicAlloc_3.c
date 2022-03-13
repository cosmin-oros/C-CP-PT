#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
3. Fibonacci strings. Fibonacci strings are defined as follows: S0 = 0, S1 = 01, Sn = Sn-1Sn-2 (concatenation).
Write a function that takes an unsigned n and returns Sn. Use at most n allocations and copy operations.
*/

char* fibStrings(int n){
    char* S0=(char*)malloc(1*sizeof(char));
    char* S1=(char*)malloc(2*sizeof(char));
    char* p=(char*)malloc(1*sizeof(char));
    int k=2;
    strcpy(S0,"0");
    strcpy(S1,"01");
    while(n-1){
        S0=(char*)realloc(S0,k*sizeof(char));
        p=(char*)realloc(p,k*sizeof(char));
        k++;
        S1=(char*)realloc(S1,k*sizeof(char));
        strcpy(p,S0);
        strcpy(S0,S1);
        strcat(S1,p);
        n--;
    }
    return S1;
}

int main(){
    char*p=fibStrings(3);
    printf("%s\n",p);
    return 0;
}
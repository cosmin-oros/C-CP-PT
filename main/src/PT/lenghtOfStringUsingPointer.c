#include <stdio.h>

#define MAXSIZE 100

int main(){
    char string[MAXSIZE];
    char *str=string;
    int lenght=0;
    printf("Enter the string:");
    gets(string);
    while(*(str++)!='\0'){
        lenght++;
    }
    printf("Lenght of the string '%s' is %d\n",string,lenght);
}
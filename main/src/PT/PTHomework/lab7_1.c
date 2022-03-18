#include <stdio.h>
#include <ctype.h>

/*
1. Write a program to replace all lowercase letters from a file containing uppercase letters.
*/

int main(){
    FILE* fptr = fopen("lab7_1.txt","r+");
    int c;
    while ((c=fgetc(fptr))!=EOF)
    {
        if (isupper(c))
        {
            c=tolower(c);
            fseek(fptr,-1L,SEEK_CUR);
            fputc(c,fptr);
        }
        
    }
    
    return 0;
}
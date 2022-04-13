#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

/*
3. Write a tool to convert from UNIX text files to DOS text files.
UNIX uses newlines encoded by only one character "\n", and DOS
uses two characters "\r\n". Use the stdin and stdout file streams.
*/

int main(){
    const char* filename = "lab7PT_3.txt";
    int c; 
    FILE* fptr = fopen(filename,"r+");
    if(!fptr){
        printf("Couldn't open the file\n");
        return -1;
    }
    while ((c = fgetc(fptr)) != EOF) { 
        if (c == '\n'){ 
            fputs("\r\n", fptr);
        }  
    }
    fclose(fptr);
    return 0;
}
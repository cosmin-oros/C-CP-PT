#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

/*
3. Write a tool to convert from UNIX text files to DOS text files.
UNIX uses newlines encoded by only one character "\n", and DOS
uses two characters "\r\n". Use the stdin and stdout file streams.
*/

int main(){
    int c; 
    while ((c = getchar()) != EOF) { 
        if (c == '\n'){ 
            fputs("\r\n", stdout);
        }
    }

    return 0;
}
#include <stdio.h>

/*
2. Write a program to read the standard input file stdin until EOF
is signaled and count the frequencies of appearances for all the
characters met. Use an array to retain the frequencies and print it
on the standard output stdout when finished. You may reuse the
code snippets from the Theoretical Summary.
*/

int main(){
    int apps[128]={0};
    char c;
    while ((c=fgetc(stdin))!=EOF)   //ctrl+d for EOF
    {
        apps[c]++;
    }
    for (int i = 0; i < 128; i++)
    {
        if (apps[i])
        {
            fprintf(stdout,"%c appears %d times\n",i,apps[i]);
        }
    }
    
    
    return 0;
}
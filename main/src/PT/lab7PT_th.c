#include <stdio.h>

int main(void){
    unsigned int n = 0;
    char c;
    while ((c=fgetc(stdin))!=EOF)
    {
        n++;
    }
    fprintf(stdout,"Just read %u chars from the input file\n",n);
    
    return n;
}
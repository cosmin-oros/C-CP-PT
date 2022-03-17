#include <stdio.h>

/*
4. Modify the previous tool so that if any arguments are given in
the command line they should be treated as files ready to be
processed. The "*.c" argument will be expanded by the shell into a
list with all the source files in the working directory
*/

int main(int argc,char** argv){
    int c;
    for (int i = 1; i < argc; i++)
    {
        FILE* fptr = fopen(argv[i],"r+");
        while ((c = fgetc(fptr)) != EOF) { 
        if (c == '\n'){ 
            fputs("\r\n", fptr);
        }  
    }
    }
    
    return 0;
}
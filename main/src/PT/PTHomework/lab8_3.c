#include <stdio.h>

/*
3. Write a file archiving program driven by command line arguments.
The program must be able to concatenate an arbitrary number
of binary files in a single ".arh" file. The user must be able to
extract any file from the archive and list the archive contents
(the file names). When given the "*" from the command line the
GNU/Linux shell will expand the list of files from the working
directory in a string containing their names separated by spaces
and provide that string as argument to your program. Basically,
all the file names from the working directory will be command
line arguments to your program helping you archive the entire
working directory
*/

int main(int argc,char** argv){
    FILE* fptr;

    if (argc < 2)
    {
        printf("Didn't provide enough arguments\n");
    }
    

    if (argv[1] != "*")
    {
        printf("Didn't provide the *\n");
        return -1;
    }

    for (int i = 1; i < argc; i++)
    {
        fptr = fopen(argv[i],"rb");
    }
    
    
    return 0;
}
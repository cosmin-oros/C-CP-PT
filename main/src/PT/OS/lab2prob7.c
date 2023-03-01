#include <stdio.h>

/*
    Write a C program that accepts 4 arguments on command line. 
    The program shall print a different message for each argument and an error message if the arguments are not present, are not enough or are too many.
*/

int main(int argc, char** argv) {
    if (argc == 1)
    {
        printf("args not present\n");
    } else if (argc < 5 && argc > 1)
    {
        printf("not enough args\n");
    } else if (argc > 5)
    {
        printf("too many args\n");
    }
    
    for (int i = 1; i < argc; i++)
    {
        printf("arg %d ", i);
    }
    printf("\n");
    

    return 0;
}
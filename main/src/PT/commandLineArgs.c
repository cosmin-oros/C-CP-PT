#include <stdio.h>
#include <stdlib.h>

int main(int argc,char** argv){
    if (argc != 2)
    {
        printf("Too many/too few arguemnts\n");
        return;
    }

    int n = atoi(argv[1]);
    printf("%d",n);

    return 0;
}
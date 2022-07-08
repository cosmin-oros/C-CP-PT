#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void generateFunctions(int n, int m){
    if (n > m)
    {
        generateFunctions(n, m-1);
    }

    
    
}

int main(int argc, char** argv){
    if (argc != 2)
    {
        printf("Didn't provide the text file\n");
        return 1;
    }
    //open the text file
    FILE* fp = fopen(argv[1],"r");
    if (!fp)
    {
        printf("Couldn't open the file");
        return 1;
    }

    char temp[20];
    //read the line
    fgets(temp,20,fp);
    int n = temp - '0';
    fgets(temp,20,fp);
    int m = temp - '0';

    generateFunctions(n,m);
    
    //close the text file
    fclose(fp);

    return 0;
}
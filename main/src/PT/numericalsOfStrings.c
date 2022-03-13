#include <stdio.h>
#include <stdlib.h>

/*
You are given an input string.
For each symbol in the string if it's the first character occurrence, replace it with a '1', 
else replace it with the amount of times you've already seen it.
*/

const char *numericals(const char *str_in) {
    int len = strlen(str_in);
    char* result=calloc(3*len,sizeof(char));
    int* arr1=calloc(256,sizeof(int));
    char* numstring=calloc(4,sizeof(char));
    char c;
    for(int i=0;i<len;i++){
        c=str_in[i];
        arr1[c]++;
        sprintf(numstring,"%d",arr1[c]);
        strcat(result,numstring);
    }
    free(arr1);
    return result;

}

int main(){
    char*p=numericals("Hello, World!");
    printf("%s\n",p);
    return 0;
}
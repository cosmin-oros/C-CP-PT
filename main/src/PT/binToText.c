#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *binary_to_string(const char *binary){
    int len=strlen(binary)/8;
    char *ascii=malloc(len+1);
    for(int i=0;i<len;i++){
        char*substr=malloc(8);
        strncpy(substr,binary+8*i,8);
        ascii[i]=strtol(substr,NULL,2);
    }
    ascii[len]='\0';
    return ascii;
}

int main(){
    char*p=binary_to_string("0100100001100101011011000110110001101111");
    printf("%s\n",p);
    return 0;
}
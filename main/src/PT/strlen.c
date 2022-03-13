#include <stdio.h>

int sLen(char* s){
    int i;
    for (i = 0; s[i]!='\0'; i++)
    {
        ;
    }
    return i;
    
}

int main(){
    printf("%d\n",sLen("Ana has 3000 apples"));
    
    return 0;
}
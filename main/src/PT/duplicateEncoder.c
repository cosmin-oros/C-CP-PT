#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

char  *DuplicateEncoder(char*word){
    char*p=calloc((strlen(word)+1),sizeof(char));
    int t[256]={0};
    for(int i=0;word[i]!='\0';i++){
        t[toupper(word[i])]++;
    }
    for(int i=0;word[i]!='\0';i++){
        if(t[toupper(word[i])]==1){
            p[i]='(';
        }
        else{
            p[i]=')';
        }
    }
    return p;

}

int main(){
    char*dupEn=DuplicateEncoder("ddabc");
    printf("%s\n",dupEn);
    return 0;
}
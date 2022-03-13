#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

char* alphabet_position(const char* text){
    char* modText=malloc(strlen(text)*sizeof(char));
    for(int i=0;text[i]!='\0';i++){
        modText[i]=tolower(text[i])-'a'+1;
    }
    return modText;
}

int main(){
    char* s=alphabet_position("Ana are mere");
    printf("%s\n",s);
    return 0;
}
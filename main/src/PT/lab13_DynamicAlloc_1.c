#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*
1 Splitting into words Write a function that splits a string into words (strings with no whitespace), 
returning a (dynamically allocated) array of pointers to (dynamically allocated) copies of the words in the string.
*/

#define DEBUG 1

char** split_into_words(char s[]){
    char** result=malloc(1*sizeof(char*));
    if(!result){
        return NULL;
    }
    int n=0;
    char*word=strtok(s," .,;?!");
    while(word){
#ifdef DEBUG
    printf("%s\n",word);
#endif
    char**aux=realloc(result,(n+1+1)*sizeof(char*));
    if(!aux){
        free(result);
        return NULL;
    }
    result=aux;
    result[n]=strdup(word);
    n++;
    word=strtok(NULL," .,;?!");
    }
    result[n]=NULL;
    return result;
}



int main(){
    char s[]="John has many apples";
    char**words=split_into_words(s);
    for(int i=0;words[i]!=NULL;i++){
        printf("%s\n",words[i]);
    }
    return 0;
}
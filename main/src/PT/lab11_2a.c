#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

char* readWord(){
    char* word=malloc(1*sizeof(char));
    if(!word){
        return NULL;
    }
    int cnt=0;
    int c;
    while(isalnum(c=getchar())){
        char* aux=realloc(word,(cnt+1+1)*sizeof(char));
        if(!aux){
            free(word);
            return NULL;
        }
        word=aux;
        word[cnt]=c;
        cnt++;
    }
    word[cnt]='\0';
    return word;
}

int countWord(char word1[],char word2[]){
    int cnt=0;
    char* s=word1;

    while((s=strstr(s,word2))!=NULL){
        cnt++;
        s=s+strlen(word2);
    }
    return cnt;
}

int main(int argc,char* argv[]){
    if(argc!=2){
        printf("Please state the word you are searching for\n");
        return -1;
    }
    char* word=argv[1];
    /*
    if(word){
        printf("Am citit %s\n",word);
    }
    else{
        printf("Nu s-a reusit citirea cuvantului\n");
    }*/
    int len=strlen(word);
    char buff[len+1];
    int cnt=0;
    while((buff=readWord())!=NULL){

        cnt+=countWord(buff,word);
        free(buff);
        int c=getchar();
        if(c==EOF) break;
        ungetc(c,stdin);
    }
    printf("We have found %d occurances\n",cnt); 
    return 0;
}
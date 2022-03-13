#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define blockSize 10

//searches stand-alone words anywhere insider buff
int containsWords(char buff[],char w[]){
    char* p;
    char*pBuff=buff;
    while((p=strstr(pBuff,w))!=NULL){
        if((p-buff==0)&&(!isalpha(p[strlen(w)]))){//beginning of the buffer
            return 1;
        }
        if((p-buff>0)&&(!isalpha(p[-1]))&&(!isalpha(p[strlen(w)]))){
            return 1
        }
        pBuff=p+1;
    }
    return 0;
}

int main(int argc,char* argv[]){
    
    if(argc!=2){
        printf("Pass the word you are searchin for as first command line arg\n");
        return -1;
    }
    char* word=argv[1];
    //printf("%d\n",containsWords("ana are mere","ana"));
    char* line=NULL;
    int blockNo=0;
    char block[blockSize];
    while(fgets(block,blockSize,stdin)!=NULL){
        
        fgets(block,10,stdin);
        char* aux=realloc(line,(blockNo+1)*blockSize*sizeof(char));
        blockNo++;
        if(!aux){
            free(line);
            return -2;//couldn't allocate enough mem
        }
        line=aux;
        strcat(line,block);
        if(line[strlen(line)-1]=='\n'){
            if(containsWord(line,word)){
                printf("Line contains word: %s\n",line);
            }
            free(line);
            line=NULL;
            blockNo=0;
        }

    }
    free(line);
    return 0;
}
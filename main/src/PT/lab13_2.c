#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

/*
2. Sort text lines Read text until end of input, splitting lines longer than 255 characters. Store the text in memory as array of pointers to lines. 
Each line is stored as a length-prefixed string: there is no '\0' terminator,
 but the first byte of a string stores its length. Sort the strings in increasing order of their lengths, breaking ties in alphabetical order.
*/

int cmpLines(const void* l1,const void* l2){
    char* ln1=*(char* const*)l1;
    char* ln2=*(char* const*)l2;
    if(strlen(ln1)!=strlen(ln2)){
        return strlen(ln1)-strlen(ln2);
    }
    else{
        return strcmp(ln1,ln2);
    }
}

/*char* myStrdup(char* s){
    char* aux=malloc(strlen(s)+2);
    if(!aux){
        return NULL;
    }
    strcpy(aux+1,s);
    aux[0]=strlen(s);
    return aux;
}
*/
int main(){
    char buff[255];
    char** lines=NULL;
    unsigned lineNo=0;
    while(fgets(buff,255,stdin)!=NULL){
        lineNo++;
        printf("The %d line is %s\n",lineNo,buff);
        char** aux=realloc(lines,(lineNo*sizeof(char*)));
        if(!aux){
            printf("Eroare la alocare\n");
            free(lines);
            return -1;
        }
        lines=aux;
        lines[lineNo-1]=strdup(buff);
    }
    qsort(lines,lineNo,sizeof(lines[0]),cmpLines);
    for(int i=0;i<lineNo;i++){
        printf("%d: %d %s\n",i,strlen(lines[i]),lines[i]);
    }
    return 0;
}
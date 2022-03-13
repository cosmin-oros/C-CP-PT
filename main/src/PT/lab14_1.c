#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*
1. Write a simple variant of the Unix strings program 
that prints all strings from a text file that contain
 at least 4 consecutive uppercase characters except space (as checked by isupper()).
*/

int isOk(char s[]){
  //  printf("Analizam %s\n", s);
    int upLen=0;
    for (int i=0; s[i]; i++){
        if (isupper(s[i])){
            upLen++;
        }
        else{
            if (upLen>=4){
                return 1;
            }
            upLen=0;
        }
    }
    if (upLen>=4){
                return 1;
    }
    return 0;
}

void print_unix_strings(FILE* p){
    
    
    int k=100;
    char* word=(char*)malloc(k*sizeof(char));
    // char *word;
    // word = (char *) calloc(1000,sizeof(char));
    // if(word==NULL){
    //     printf("Couldn't allocate memory\n");
    //     exit(0);
    // }

    if(word==NULL){
        printf("Memory not allocated\n");
        return ;
    }
    else{
       //d printf("Word is ok");
    }

    //printf("Word este %p\n", word);

    int i=0;
    int c;
    while ((c=fgetc(p))!=EOF){

        //putchar(c);
        if (!isspace(c)){
            if(i<k){
                word[i]=c;
                i++;
            }
            else{
                k+=100;
                char *aux=(char*)realloc(word,k*sizeof(char));
                if (!aux){
                    free(word);
                    return ;
                }
                else{
                    word=aux;
                }
            }
        }
        else {
            if (isOk(word)){
                printf("%s\n", word);
            }
            i=0;
            memset(word, 0, 1000);
        }

    }
    
        free(word);
    
    // int k=0;
    // while(p!=EOF){
    //     k=0;
    //     fscanf(p,"%c",&a);
    //     while(isalpha(a) && isupper(a)){
    //         word[k]=a;
    //         fscanf(p,"%c",&a);
    //         k++;
    //     }

    //     if(k>=3){
    //         while(isalpha(a)){
    //             word[k]=a;
    //             fscanf(p,"%c",&a);
    //             k++;
    //         }
    //         for(int i=0;i<k;i++){
    //             printf("%c",word[i]);
    //         }
    //     }
    // }
}

int main(int argc, char* argv[]){
    FILE *fptr;
    fptr=fopen(argv[1],"r");
    if(fptr == NULL)
    {
      printf("Error! Nu am deshcis fiiserul\n");   
      exit(1);             
    }
    print_unix_strings(fptr);
    fclose(fptr);
    return 0;
}
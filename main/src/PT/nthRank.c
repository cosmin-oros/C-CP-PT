#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>



typedef struct cuvant{
    char* s;
    int wn;
} cuv_t;


typedef struct result{
    cuv_t* words;
    int nWords;
}result_t;


int cmpWords(const void *n1, const void *n2){

    cuv_t nr1=*(cuv_t*)n1;
    cuv_t nr2=*(cuv_t*)n2;

    return nr1.wn-nr2.wn;

}

int compWN(char*s , int we){
    int N=0;
    for (int i=0; s[i]; i++){
        N=N+(s[i]-'a'+1);
    }
    return N*we;
}

result_t splitWords(char *s, int we[]){


    printf("Aici");
    int n=0;
    cuv_t* words=malloc((n+1)*sizeof(cuv_t));
    if(!words){
        result_t r=(result_t){"",0};
        return r;
    }

    // char *cuv=strtok(s, ",");
    // while (cuv!=NULL){
    //     words[n].s=strdup(cuv);
    //     words[n].wn=compWN(cuv, we[n]);
    //     n++;
    //     cuv=strtok(NULL,",");
    // }

    // printf("Am gasit %d cuvinte\n", n);
    // result_t r;
    // r.words=words;
    // r.nWords=n;
    // return r;
}


cuv_t nthRank(char* st, int* we, int n) {
    // int som;
    // int k=0;
    // int a;
    // int winningNumber[100]={0};
    // for(int i=0;st[i]!='\0';i++){
    //     som=0;
    //     while(st[i]!=','){
    //         som+=(tolower(st[i])-'a')+1;
    //         i++;
    //     }
    //     winningNumber[k]+=(som*we[k]);
    //     k++;
    //     som=0;
    // }

    printf("Aiic");
    result_t r=splitWords(st, we);

    //qsort(r.words, r.nWords, sizeof(r.words[0]), cmpWords );
    return r.words[n];
    // for(int i=0;winningNumber[i]!='\0';i++){
    //     for(int j=i+1;winningNumber[j]!='\0';j++){
    //         if(winningNumber[i]<winningNumber[j]){
    //             a=winningNumber[i];
    //             winningNumber[i]=winningNumber[j];
    //             winningNumber[j]=a;
    //         }
    //     }
    // }
    //...
    //return 
}

int main(){
    int we[]={1,4,4,5,2,1};
    cuv_t w=nthRank("COLIN,AMANDBA,AMANDAB,CAROL,PauL,JOSEPH",we,2);
    //printf("%s\n", w.s);
    return 0;
}
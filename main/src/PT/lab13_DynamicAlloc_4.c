#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
/*
4. Print from address array Write a function int myprintf(const char *fmt, void *adrtab[]) that works like printf, 
but receives a NULL-terminated array of addresses (void *) of objects to be printed.
Implement the format specifiers %d, %f and %s, as well as printing ordinary characters and %.
 An error encountered in the format should terminate printing.
*/

void myprintf(const char* fmt, void* adrtab[]){
    char* s;
    int printed=0;
    for(s=fmt;*s!='\0';s++){
        while(*s!="%"){
            putchar(*s);
            s++;
        }
        s++;
        switch(*s){
            case 'd' :
            for(int i=0;*adrtab[i]!=NULL;i++){
                if(isdigit((int*)*adrtab[i])){
                    printf("%d",(int*)*adrtab[i]);
                    printed=1;
                }
            }
            if(printed==0){
                printf("*Invalid specifier*");
                break;
            }
            printed=0;
            case 'f' :
            for(int i=0;*adrtab[i]!=NULL;i++){
                if(isdigit((float*)*adrtab[i])){
                    printf("%f",(float*)*adrtab[i]);
                    printed=1;
                }
            }
            if(printed==0){
                printf("*Invalid specifier*");
                break;
            }
            printed=0;
            case 's' :
            for(int i=0;*adrtab[i]!=NULL;i++){
                if(isalpha((char*)*adrtab[i])){
                    printf("%s",(char*)*adrtab[i]);
                    printed=1;
                }
            }
            if(printed==0){
                printf("*Invalid specifier*");
                break;
            }
            printed=0;
        }
    }
}

int main(){
    int numbers[]={2};
    char string[]="si le manca :|";
    void* adrtab[2];
    *adrtab[0]=*numbers;
    *adrtab[1]=*string;
    myprintf("Ana are %d mere %s",adrtab);
    return 0;
}
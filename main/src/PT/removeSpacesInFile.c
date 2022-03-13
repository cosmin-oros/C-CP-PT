#include <stdio.h>
#include <ctype.h>

int main(){
    FILE * pfile;
    int a;
    pfile=fopen("file.txt","r");
    if(pfile){
        do{
            a=fgetc(pfile);
            if(isgraph(a)){
                putchar(a);
            }
        }while(a!=EOF);
        fclose(pfile);
    }
    printf("\n");
    return 0;
}
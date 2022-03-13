#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

void read(FILE* f){
    int c;
    while((c=fgetc(f))!=NULL){
        
    }
}

int main(int argc,char* argv[]){
    FILE* f;
    char buf[100];
    if(argc==2 && (f=fopen(argv[1],"r"))){
        read(f);
        fclose(f);
    }
    else{
        printf("Couldn't read from file\n");
    }
    return 0;
}
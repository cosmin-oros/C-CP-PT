#include <stdio.h>
#include <ctype.h>

void printWords(char str[]){
    for(int i=0;str[i]!='\0';i++){
        do{
            if(isalpha(str[i])){
                putchar(str[i]);
            }
            i++;
        }while(str[i]!=' ');
        printf("\n");
    }
}

int main(){
    char str[10];
    fgets(str,10,stdin);
    printWords(str);
    return 0;
}
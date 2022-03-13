#include <stdio.h>

int lastOccurance(char* str,int toFind){
    int index=-1;
    int i=0;
    while(str[i]!='\0'){
        if(str[i]==toFind){
            index=i;
        }
        i++;
    }
    return index;
}

int main(){
    char str[100];
    char toFind;
    int index;
    printf("Enter the string:\n");
    gets(str);
    printf("Enter the character to find:\n");
    toFind=getchar();
    index=lastOccurance(str,toFind);
    if(index>=0){
        printf("\nLast occurance of '%c' is on position %d\n",toFind,index);
    }
    else{
        printf("Couldn't find character '%c'\n",toFind);
    }
    return 0;
}
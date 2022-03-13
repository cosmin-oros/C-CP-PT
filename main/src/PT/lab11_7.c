#include <stdio.h>
#include <string.h>
/*
7. Concatenate strings Write a function that takes a NULL-terminated array of strings (string = char *), 
another string buf and a maximal length, and concatenates all strings from the array into buf, separated by one space, 
without exceeding the length limit.
 Avoid strcat and maintain a pointer to the end of the string being constructed.
*/

void makeSentence(char* s[], char buf[], int maxLenght){
    int lenght=0,i=0;
    char *p=buf;
    int a=0;
    while(s[i]!='\0'){
        lenght+=strlen(s[i]);
        if(lenght<=maxLenght){
            strcpy(p,s[i]);
        }
        else{
            a=1;
            printf("Buf overflow\n");
        }
        i++;
        p++;
        p=" ";
        lenght++;
        if(a){
            a=1;
            printf("Buf overflow\n");
        }
    }
    if(a==0){
        p='\0';
        p=buf;
        while(p!=NULL){
        printf("%s",p);
        p++;
    }
    }
}

int main(){
    char* s[]={"John","has","apples",NULL};
    char buf[50];
    int maxLenght=50;
    makeSentence(s,buf,maxLenght);
    return 0;
}
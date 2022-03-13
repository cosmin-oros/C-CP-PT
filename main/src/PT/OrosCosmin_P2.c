#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int extractSubstrings(char* subStrings[],int capacity,char* s){
    int lenght=0;
    for(int i=0;s[i]!='\0';i++){
        if(strlen(s[i])==5 && isupper(s[0][i])){
            if(isupper(s[0][i])=='A' || isupper(s[0][i])=='E' || isupper(s[0][i])=='I' || isupper(s[0][i])=='O' || isupper(s[0][i])=='U'){
                if(lenght<=capacity){
                    subStrings[lenght]=s[i];
                    lenght++;
                    printf("%s ",s[i]);
                }
                else{
                    printf("Overflow\n");
                }
            }
        }
    }
    if(lenght<=capacity){
        return lenght;
    }
}

int main(){
    const char *s[2]={"Abcde","bcd"};
    char subStrings[5]={0};
    printf("%d",extractSubStrings(subStrings,5,s));
    return 0;
}
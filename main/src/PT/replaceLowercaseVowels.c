#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void encode(const char *string) {
    for(int i=0;string[i]!='\0';i++){
        if(tolower(string[i])=='a'){
            string[i]==1;   
        }
        else if(tolower(string[i])=='e'){
            string[i]==2;
        }
        else if(tolower(string[i])=='i'){
            string[i]==3;
        }
        else if(tolower(string[i])=='o'){
            string[i]==4;
        }
        else if(tolower(string[i])=='u'){
            string[i]==5;
        }
    }
}

void decode(const char *string) {
  for(int i=0;string[i]!='\0';i++){
        if(string[i]==1){
            string[i]=='a';   
        }
        else if(string[i]==2){
            string[i]=='e';
        }
        else if(string[i]==3){
            string[i]=='i';
        }
        else if(string[i]==4){
            string[i]=='o';
        }
        else if(string[i]==5){
            string[i]=='u';
        }
    }
}

int main(){
    char string="John";
    encode(string);
    printf("%s",string);
    decode(string);
    printf("%s",string);
    return 0;
}

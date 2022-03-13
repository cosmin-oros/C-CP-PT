#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

char* Rot(char* string){
    char* newString = malloc(strlen(string)*sizeof(char));
    for (int i = 0; string[i]!='\0'; i++)
    {
        if (isalpha(string[i]))
        {
            if(islower(string[i])){
                if(string[i]+13<='z'){
                    newString[i]=string[i]+13;
                }
                else{
                    int k=0;
                    char temp=string[i];
                    while(temp<='z'){
                        temp++;
                        k++;
                    }
                    newString[i]='a'+(13-k);
                }
            }
            else{
                if(string[i]+13<='Z'){
                    newString[i]=string[i]+13;
                }
                else{
                    int k=0;
                    char temp=string[i];
                    while(temp<='Z'){
                        temp++;
                        k++;
                    }
                    newString[i]='A'+(13-k);
                }
            }
        }   
        else{
            newString[i]=string[i];
        }
        
    }
    
    return newString;
}

int main(){
    char* s = Rot("Ana are 13 mere");
    printf("%s\n",s);
    return 0;
}
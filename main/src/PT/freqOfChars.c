#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
    char str[1500];
    int c=0,count[26]={0};
    printf("Enter a string:\n");
    gets(str);
    while(str[c]!='\0'){
        if((tolower(str[c]))>='a' && (tolower(str[c]))<='z'){
            count[tolower(str[c])-'a']++;
        }
        c++;
    }
    for(int i=0;i<26;i++){
        if(count[i]){
            printf("Character %c occurs %d times in the string\n",i+'a',count[i]);
        }
    }
    return 0;
}
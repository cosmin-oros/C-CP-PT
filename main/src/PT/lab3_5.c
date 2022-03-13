/*
5. Nested comments Comments in the ML language start with (* and end with *). Comments may be nested. 
Write a program that reads input with potentially nested comments and prints out everything except the comments. 
Hint: Remember how many comment levels are open at any time.
*/
#include <stdio.h>
#include <ctype.h>

int startOfComment(int c){
    if(c=='/' && c=getchar()=='*'){
        return 1;
        ungetc(c,stdin);
    }
    else{
        return 0;
        ungetc(c,stdin);
    }
}

int endOfComment(int c){
    if(c=='*' && c=getchar()=='/')
    {
        return 1;
        ungetc(c,stdin);
    }
    else{
        return 0;
        ungetc(c,stdin);
    }
}

int main(){
    int c,start=0,nest=0,end=0;
    while(c=getchar()!=EOF){
        start=startOfComment(c);
        end=endOfComment(c);
    }
    return 0;
}
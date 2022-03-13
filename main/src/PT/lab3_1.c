#include <stdio.h>
#include <stdlib.h>
/*
1. Collapse spaces Write a program that reads all input (from standard input) and prints it transformed as follows:
any sequence of whitespace that does not contain newline is replaced with a single space character
whitespace characters immediately before a newline are deleted.
*/
void remove_spaces(){
    int a;
    while((a=getchar())==' '){
        
    }ungetc(a,stdin);
}
void print_non_whitespaces(){
    int a;
    while((a=getchar())!=' ' && a!=EOF){
        putchar(a);
    } 
    ungetc(a,stdin);
}
int main(){
    int a;
    while((a=getchar())!=EOF){
        ungetc(a,stdin);
        remove_spaces();
        print_non_whitespaces();
        putchar(' ');
    }

    return 0;
}
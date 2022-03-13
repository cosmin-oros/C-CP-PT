/*
3. Fixed-width printing Write a function that takes an unsigned n as a parameter, and prints a text read until the end of input, 
fitting n characters per line. Words(sequences of non-whitespace chars) are printed with one space in between. 
A word that would exceed the line limit will be split inserting a hyphen ('-') as the last character on the line 
(no extra hyphen is needed if the last character that fits is a hyphen itself). Newlines in the original text are observed. 
Hint: to handle the end of the line, 
write a function peek() which returns the next character without consuming it (use ungetc()).
*/
#include <stdio.h>
#include <ctype.h>
int peek(){
    int a;
    a=getchar();
    ungetc(a,stdin);
    return a;
}

void print_words(unsigned n){
    int c,word;
    while(n){
        c=getchar();
        word=0;
        n--;
        if(isalnum(c)){
            putchar(c);
            word=1;
        }
        if(peek()==' '){
            printf(" ");
        }
        if(n==1 && word && isalnum(peek())){
        printf("-");
        n--;
        }
    }
    printf("\n");
}

int main(){
    unsigned n=6;
    int c;
    while((c=getchar())!=EOF){
        ungetc(c,stdin);
        print_words(n);
    }
    return 0;
}
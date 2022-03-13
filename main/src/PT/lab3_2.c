#include <stdio.h>
#include <ctype.h>
/*
2. Paragraph info Write a program that reads all input and prints, for each paragraph, the number of words and lines. 
A paragraph is a portion of text that does not start with a newline, 
ends with a single newline or EOF and is separated by at least one newline from other paragraphs.
*/



void skipNL(){
    int c;
    
}

void wordsAndLines(int p){
    int c,words=0,lines=1;
    skipNL();
    

}

int main(){
    int c,p=1;
    while((c=getchar())!=EOF){
        ungetc(c,stdin);
        wordsAndLines(p);
        p++;
    }
    
    return 0;
}
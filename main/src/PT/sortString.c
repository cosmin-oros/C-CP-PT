#include <stdio.h>
#include <string.h>
char *order_words (char *ordered, const char *words)
{
	char* retval = ordered;
    const char* wordptr;
    for(int i=1;(wordptr=strchr(words,i+'0'));i++){
        while(wordptr>words && wordptr[-1]!=' '){
            wordptr--;
        }
        for(;(*wordptr!='\0')&&(*wordptr!=' ');wordptr++){
            *(ordered++)=*wordptr;
        }
        *(ordered++)=' ';
    }
    ordered[(retval==ordered) ? 0 : -1]='\0';
    return retval;
}

int main(){
    char o[100];
    char* s = order_words(o,"is2 Thi1s 3a t4est");
    printf("%s\n",s);
    return 0;
}
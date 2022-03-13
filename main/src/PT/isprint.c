#include <stdio.h>
#include <ctype.h>

int main(){
    int ctr=0;
    char str[]="John has apples \n he eats them \n";
    while(isprint(str[ctr])){
        putchar(str[ctr]);
        ctr++;
    }
    printf("\n");
    return 0;
}
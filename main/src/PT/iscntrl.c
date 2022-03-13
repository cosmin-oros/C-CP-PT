#include <stdio.h>
#include <ctype.h>

int main(){
    int i=0,j=0;
    char str1[]="Ana \a are \t mere";
    char str2[]="Ion nu are \n mere";
    while(!iscntrl(str1[i])){
        putchar(str1[i]);
        i++;
    }
    while(!iscntrl(str2[i])){
        putchar(str2[i]);
        j++;
    }
    return 0;
}
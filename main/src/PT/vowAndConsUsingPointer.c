#include <stdio.h>
#include <ctype.h>

int main(){
    char str1[50];
    char *pt;
    int ctrV=0,ctrC=0;
    fgets(str1,sizeof(str1),stdin);
    pt=str1;    //pt=adress of str1
    while(*pt!='\0'){
        int a=*pt;
        a=tolower(a);
        if(isalpha(a)){
        if(a=='a' || a=='e' || a=='i' || a=='o' || a=='u'){
            ctrV++;
        }
        else{
            ctrC++;
        }
        }
        pt++;
    }
    printf("Nr of vowels:%d | Nr of consonants:%d\n",ctrV,ctrC);
    return 0;
}
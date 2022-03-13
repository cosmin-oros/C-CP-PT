#include <stdio.h>
    //compare two strings without strcmp

int comp(char* str1,char* str2){
    int i=0;
    while(str1[i]==str2[i]){
        if(str1[i]=='\0'&&str2[i]=='\0'){
            break;
        }
        i++;
    }
    return str1[i]-str2[i];
}

int main(){
    char str1[100],str2[100];
    printf("Input string1:\n");
    gets(str1);
    printf("Input string2:\n");
    gets(str2);
    if(comp(str1,str2)){
        printf("The strings are different\n");
    }
    else{
        printf("The strings are the same\n");
    }
    return 0;
}
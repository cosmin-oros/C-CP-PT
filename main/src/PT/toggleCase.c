#include <stdio.h>

void tog(char* str){
    int i=0;
    while(str[i]!='\0'){
        if(str[i]>='a'&&str[i]<='z'){
            str[i]-=32;
        }
        else if(str[i]>='A'&&str[i]<='Z'){
            str[i]+=32;
        }
        i++;
    }
}

int main(){
    char str[100];
    printf("Enter the string:\n");
    gets(str);
    printf("String before toggling case: %s\n",str);
    tog(str);
    printf("String after toggling case: %s\n",str);
    return 0;
}
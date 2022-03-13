#include <stdio.h>

int main(){
    char str[80],search[20];
    int c1=0,c2=0,i,j,flg;
    printf("Input the string:\n ");
    fgets(str,sizeof(str),stdin);
    printf("Input the substring to be searched:\n ");
    fgets(search,sizeof(search),stdin);
    while(str[c1]!='\0'){
        c1++;
    }
    c1--;
    while(search[c2]!='\0'){
        c2++;
    }
    c2--;
    for(i=0;i<=c1-c2;i++){
        for(j=i;j<i+c2;j++){
            flg=1;
            if(str[j]!=search[j-i]){
                flg=0;
                break;
            }
        }
        if(flg==1){
            break;
        }
    }
    if (flg==1){
        printf("The substring exists in the string\n");
    }
    else{
        printf("The substring doesn't exist in the string\n");
    }
    return 0;
}
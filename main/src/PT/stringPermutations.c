#include <stdio.h>
#include <string.h>

void changePos(char *ch1,char *ch2){
    char t;
    t=*ch1;
    *ch1=*ch2;
    *ch2=t;
}

void charPerm(char *str,int start,int end){
    if(start==end){
        printf("%s ",str);
    }
    else{
        for(int i=start;i<end;i++){
            changePos((str+start),(str+i));
            charPerm(str,start+1,end);
            changePos((str+start),(str+i));
        }
    }
}

int main(){
    char str[]="abcd";
    int len=strlen(str);
    charPerm(str,0,len);
    return 0;
}
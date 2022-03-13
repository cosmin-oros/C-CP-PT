#include <stdio.h>
#include <string.h>

int if_char_exists(char c,char p[],int x,int y[]){
    int i;
    for(i=0;i<=x;i++){
        if(p[i]==c){
            y[i]++;
            return 1;
        }
    }
    if(i>x){
        return 0;
    }
} 

int main(){
    char str1[80],chr[80];
    int n,i,x,ctr[80];
    scanf("%s",str1);
    n=strlen(str1);
    chr[0]=str1[0];
    ctr[0]=1;
    x=0;
    for(i=1;i<n;i++){
        if(!if_char_exists(str1[i],chr,x,ctr)){
            x++;
            chr[x]=str1[i];
            ctr[x]=1;
        }
    }
    for(i=0;i<=x;i++){
        printf("%c %d times\n",chr[i],ctr[i]);
    }
    return 0;
}
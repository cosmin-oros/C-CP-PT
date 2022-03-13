#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void reverse(char* src,char* dst,int len){
    for(int i=0;i<len;i++){
        dst[i]=src[len-1-i];
    }
}
void rotate(char* src,char* dst,int len){
    char head=src[0];
    for(int i=1;i<len;i++){
        dst[i-1]=src[i];
    }
    dst[len-1]=head;
}

int check_sum_of_digital(char* src,int len){
    int s=0;
    for(int i=0;i<len;i++){
        s+=src[i]%2;
    }
    return s%2;
}

char* revrot(char* s,int sz){
    if(strlen(s)<sz || strlen(s)<=0){
        return "";
    }
    int length= strlen(s) /sz*sz+1;
    char* dst=(char*)malloc(sizeof(char)*length);
    if(!dst){
        return NULL;
        free(dst);
    }
    for(int i=0;i<length-i;i+=sz){
        if(!check_sum_of_digital(s+i,sz)){
            reverse(s+i,dst+i,sz);
        }
        else{
            rotate(s+i,dst+i,sz);
        }
    }
    dst[length-1]=0;
    return dst;
}

int main(){
    char* s=revrot("123456987654",6);
    printf("%s\n",s);
    return 0;
}
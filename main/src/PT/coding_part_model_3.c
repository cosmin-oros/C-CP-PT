#include <stdio.h>
#include <stdint.h>
#include <ctype.h>

char* fillArray(uint8_t* a,unsigned sizeA,char*s,unsigned sizeS){
    unsigned k=-1;
    for(unsigned i=0;i<sizeA;i++){
        if(isprint(a[i])){
            s[k++]=a[i];
        }
        if(k>=sizeS){
            return NULL;
        }
    }   
    return s;
}

int main(){
    uint8_t* a={0xFF,0x1,0x3A};
    unsigned sizeA=3;
    char s[10];
    unsigned sizeS=10;
    char*p=fillArray(a,sizeA,s,sizeS);
    if(p!=NULL){
        printf("%s\n",p);
    }
    else{
        printf("Character limit exceeded\n");
    }
    return 0;
}
#include <stdio.h>
#include <stdint.h>

int check(uint16_t a,uint64_t b){
    uint64_t mask;
    uint64_t bCopy=b;
    uint16_t aCopy=a;
    int found=0;
    while(aCopy){
        mask=(aCopy&0xF);
        while(bCopy){
            if((bCopy&0xF)==mask){
                found=1;
            }
            bCopy=bCopy>>4;
        }
        if(found==0){
            return 0;
        }
        bCopy=b;
        aCopy=aCopy>>4;
        found=0;
    }
    return 1;
}

int main(){
    uint16_t a=0xAB12;
    uint64_t b=0xAB32DFF1278;
    if(check(a,b)){
        printf("True\n");
    }
    else{
        printf("False\n");
    }
    return 0;
}
#include <stdio.h>
#include <stdint.h>
uint32_t rotswap(uint32_t n){
    n=(n<<4)|(n>>28);
    return ((n<<16)|(n>>16));
} 

uint32_t min(uint32_t n){
    uint32_t a=n,min=n;
    while((a=rotswap(a))!=n){
        if(a<min){
            min=a;
        }
        return min;
    }
}

int main(){
    printf("%x\n",min(0x4321));
    return 0;
}
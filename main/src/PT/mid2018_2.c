#include <stdio.h>

unsigned swap_nibbles(unsigned c){
    unsigned result=0;
    for(int i=1;i<=(sizeof(c)*8)/4;i++){ 
        result=result<<4;
        unsigned nibble=c&0xF;
        result=result|nibble;
        c=c>>4;
        
    }
    return result;
}
int main(){
    printf("%x\n",swap_nibbles(0xAF));
    return 0;
}
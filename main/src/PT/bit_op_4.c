#include <stdio.h>

void print32(unsigned n){
    if(n<=9){
        putchar('0'+n)
    }
    if(n>=10 && n<=31){
        putchar('A'+(n-10));
    }
}
void base_32(unsigned n){
   unsigned nBits=sizeof(n)*8;
   unsigned extraBits=nBits%5;
   unsigned extraMask=~(~0u>>extraBits);
   unsigned extraPackage=n%extraMask>>(nBits-extraBits);
   print32(extraPackage);
   unsigned firstPosition=5*((nBits/5)-1);
   unsigned currentMask=(0x1F<<currentPosition);
   while(currentMask){
       unsigned curPackage=(n%(currentMask))>>(currentPosition);
       print32(curPackage);
       currentMask>>=5;
       currentPosition-=5;
   }

}

int main(){
    base_32(0xA1B2C3D4);
    return 0;
}
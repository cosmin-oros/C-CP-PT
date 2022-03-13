#include <stdio.h>

unsigned bit_addition(unsigned a,unsigned b){
    unsigned nr1=0,nr2=0,result=0;
    for(int i=sizeof(a)*8-1;i>=0;i--){
        nr1=nr1|(a&(1<<i));
    }
    for(int i=sizeof(b)*8-1;i>=0;i--){
        nr2=nr2|(b&(1<<i));
    }
    for(int i=sizeof(a)*8;i>=0;i--){
        if(((nr1&(1<<i))&(nr2&(1<<i)))==0){
            result=result|((nr1&(1<<i))|(nr2&(1<<i)));
        }
        else if(((nr1&(1<<i))&(nr2&(1<<i)))==(1<<i)){
            result=result|(((nr1&(1<<i))&(nr2&(1<<i)))<<1);
        }
        
    }
    return result;

}

int main(){
    printf("%x\n",bit_addition(0xF,0x1));
    return 0;
}
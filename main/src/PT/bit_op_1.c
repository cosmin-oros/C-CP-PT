#include <stdio.h>
void printBin(unsigned n){
    for(int i=sizeof(n)*8-1;i>=0;i--){
        if((n&(1<<i))==0){
            putchar('0');
        }
        else putchar('1');
    }
}

unsigned reverseNibbles_a(unsigned n){
    unsigned result=0;
    for(int i=1;i<=(sizeof(n)*8)/4;i++){ 
        result=result<<4;
        unsigned nibble=n&0xF;
        result=result|nibble;
        n=n>>4;
        
    }
    return result;
}

unsigned reverseNibbles_b(unsigned n){
    unsigned result=0;
    for(int i=0;i<(sizeof(n)*8)/4;i++){ 
        unsigned nibble=n&(0xF<<(4*i))>>(4*i);
        unsigned b=0;
        for(int j=1;j<=4;j++){
            unsigned a=nibble&(1<<j);
            if(j==1){
                a<<3;
            }
            else if(j==2){
                a<<1;
            }
            else if(j==3){
                a>>1;
            }
            else if(j==4){
                a>>3;
            }
            b=b|a;
        }
        result=result|b;
        n=n>>4;
        
    }
    return result;
}


int main(){
    printf("%x\n",reverseNibbles_a(0xABCD1234));///4321 DCBA
    printf("%x\n",reverseNibbles_a(0xB));///B000 0000
    printf("%x\n",reverseNibbles_a(~0u));
    printf("%x\n",reverseNibbles_b(0xF));//F
    return 0;
}
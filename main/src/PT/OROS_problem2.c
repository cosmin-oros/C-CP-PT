#include <stdio.h>
#include <stdint.h>
unsigned nibblesa_are_found_in_b(uint16_t a,uint64_t b){
    int mask,c,d,e,contor=0;
    while(a){
        mask=0xF;
        c=a&mask;   //we copy the value of the respective nibble of a in c in order not to destroy the value of a
        d=0;
        for(int i=1;i<=4;i++){  //we reverse the bits in the nibble so that we can compare them with each nibble of b
            if(i==1){
                d=d|((c&(1<<i))<<3);
            }
            if(i==2){
                d=d|((c&(1<<i))<<1);
            }
            if(i==3){
                d=d|((c&(1<<i))>>1);
            }
            if(i==4){
                d=d|((c&(1<<i))>>3);
            }
        }
        e=b;    //we put the value of b in e so that we dont destroy the value of b
        while(e){
            if(d==(e&0xF)){     //e&0xF is the respective nibble of b,we check if d is equal to it(if the reversed nibble is found in b)
                contor=1;
            }
            e>>4;   //we go to the next nibble and we repeat this procedure until e is 0
        }
        if(contor==0){  //if we didn't find the reversed value of the nibble from a in b we can conclude that not all the nibbles of a will be found reversed in b
            return 0;
        }
        a>>4;   //we check for the next nibble of a
    }
    return 1;   
}

int main(){
    if(nibblesa_are_found_in_b(0x21BA,0xA3B2D1F278)){
        printf("All the nibbles of a are to be found into b,in the opposite/reverse order");
    }
    else{
        printf("Not all the nibbles of a are to be found into b,in the opposite/reverse order");
    }
    return 0;
}
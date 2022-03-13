#include <stdio.h>

/*
4) 12-bit ints. An array of bytes (unsigned char) stores unsigned integers, each represented using 12 bits 
(two integers fit in three bytes). 
Bits are used least significant first, 
thus the low-order nibble of the second char in triple forms the high-order  bit of the first number, 
and the high-order nibble forms the low-order four bits of the second number. 
(A nibble is 4 bits from a byte). Write a function that takes an array and its byte length and prints all numbersin hexadecimal. 
(This encoding was used for the FAT-12 file allocation table in DOS).
*/

void print(unsigned char arr[],int lenght){
    unsigned char a=0u;
    for(int i=0;i<lenght;i++){
        if((arr[i]>>4)!=0 && a==0){
            a|=arr[i];
            i++;
            a=a|((arr[i]&0xF)<<8);
            arr[i]>>4;
            i--;
        }
        else if((arr[i]>>4)==0 && a==0){
            a|=arr[i];
            i++;
            a=a|((arr[i])<<4);
            arr[i]>>8;
        }
        
        printf("%x ",a);
        a=0u;
        
    }
}

int main(){
    unsigned char arr[]={0x12,0xAB,0x34,0xCD,0x56};
    int size=sizeof(arr)/sizeof(arr[0]);
    print(arr,size);
    return 0;
}
#include <stdio.h>
#include <stdint.h>
/*
3. Every other bit a) Write a function that takes a 32-bit unsigned and returns the 16-bit number formed by the bits in even positions.
b) The same problem, but place the bits in reverse order.
*/

uint16_t reverseBits(uint16_t num)
{
    uint16_t  NO_OF_BITS = sizeof(num) * 8;
    uint16_t reverse_num = 0, i, temp;
  
    for (i = 0; i < NO_OF_BITS; i++)
    {
        temp = (num & (1 << i));
        if(temp)
            reverse_num |= (1 << ((NO_OF_BITS - 1) - i));
    }
   
    return reverse_num;
}

uint16_t bitsInEvenPos(uint32_t a){
    unsigned mask=1;
    unsigned pos=1;
    uint16_t result=0;
    while(a){
        if(pos%2==0){
            result=result|(a&mask);
            result<<=1;
        }
        a>>=1;
        pos++;
    }
    result=reverseBits(result);
    return result;
}

int main(){
    uint32_t x = 0xFF;
    uint16_t a = bitsInEvenPos(x);
    printf("%x\n",a);
    return 0;
}
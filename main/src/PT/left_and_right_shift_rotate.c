#include <stdio.h>

unsigned int _rotl(unsigned int value, int shift) {
    if ((shift &= 31) == 0){
        return value;
    }
    return (value << shift) | (value >> (32 - shift));
}

unsigned int _rotr(unsigned int value, int shift) {
    if ((shift &= 31) == 0)
    {
        return value;
    }
    return (value >> shift) | (value << (32 - shift));
}

int main(){
    printf("%x\n",_rotl(0xAF));
    printf("%x\n",_rotr(0xAF));
    return 0;
}
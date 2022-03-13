#include <stdio.h>

long long unsigned int change_endianness(long long unsigned int N,long long unsigned int K){
    long long unsigned int number=N>>(K*8);
    while(K){
        K--;
        number=number<<8;
        number=number|(N&0xFFULL);
        N=N>>8;
    }
    return number;
}

int main(){
    printf("%llx\n",change_endianness(0x12345678,3));
    return 0;
}
#include <stdio.h>

int main(){
    float x=18.625;
    unsigned ux=*(unsigned*)&x;
    printf("%x\n",ux);
    return 0;
}
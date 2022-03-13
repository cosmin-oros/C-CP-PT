#include <stdio.h>

unsigned change_base(unsigned n,unsigned i){
    
    if(n<10){
        return n*i;
    }
    else{
        return change_base(n/10,i*16)+n%10*i;
    }
}

int main(){
    printf("%d\n",change_base(312,1));
    return 0;
}
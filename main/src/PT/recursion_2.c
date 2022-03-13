#include <stdio.h>
//number formed by the digits on even positions
unsigned select_digits(unsigned n){
    static int nr=0,invers=0,contor=0;
    contor++;
    if(contor%2==0 && n>9){
        nr=nr*10+n%10;
        select_digits(n/10);
    }
    else if(contor%2!=0 && n>9){
        select_digits(n/10);
    }
    else{
        if(contor%2==0){
        nr=nr*10+n%10;
    }
        while(nr){
            invers=invers*10+nr%10;
            nr=nr/10;
        }
        return invers;
    }
}

int main(){
    printf("%d\n",select_digits(532426));
    return 0;
}
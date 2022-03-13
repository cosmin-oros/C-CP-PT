#include <stdio.h>

unsigned s(unsigned n){
    if(n<=1){
	return 1;
    }
    else{
	return s(n-1)+n;
    }
}

int main(){
    printf("%d\n",s(3));
    return 0;
}
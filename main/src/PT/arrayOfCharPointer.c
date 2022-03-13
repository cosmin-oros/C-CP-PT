#include <stdio.h>

const int nr=4;

int main(){
    char *names[]={"Google","Amazon","Toshiba","Sony"};
    for(int i=0;i<nr;i++){
        printf("Value of names[%d] = %s\n",i,names[i]);
    }
    return 0;
}
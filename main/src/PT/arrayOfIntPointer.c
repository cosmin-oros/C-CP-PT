#include <stdio.h>

int main(){
    int var[]={10,100,200};
    int nr=3;
    int *p[nr];
    for(int i=0;i<nr;i++){
        p[i]=&var[i];
    }
    for(int i=0;i<nr;i++){
        printf("Value of var[%d] = %d\n",i,*p[i]);
    }
    return 0;
}
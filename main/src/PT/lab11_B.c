#include <stdint.h>
#include <stdio.h>

/*
B) Write a function int countAlignedAddresses(int *addr[ ]) which counts and returns how many addresses stored in the array end with 4 bits of 0. 
The array addr is guaranteed to end with a NULL pointer, which should not be processed.
*/

int countAlignedAddresses(int *addr[]){
    int counter=0;
    for(int i=0;addr[i]!=NULL;i++){
        if(((uint64_t)addr[i]&0xF)==0){
            counter++;
        }
    }
    return counter;
}

int main(){
    int v[]={1,2,3,4,5};
    int *addr[5];
    int n=sizeof(v)/sizeof(v[0]);

    for(int i=0;i<n;i++){
        addr[i]=&v[i];
    }
    printf("%d\n",countAlignedAddresses(addr));
    return 0;
}
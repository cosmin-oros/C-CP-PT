#include <stdio.h>
#include <stdlib.h>

unsigned find_number(const unsigned *arr, size_t len)
{
    unsigned nrArr[len+1]={0};
    for(int i=0;i<len;i++){
        nrArr[arr[i]]++;
    }    
    for(int i=1;i<=len;i++){
        if(!nrArr[i]){
            return i;
        }
    }
}

int main(){
    unsigned arr[]={1,3,4}
    unsigned n=find_number(arr,sizeof(arr));
    printf("%u\n",n);
    return 0;
}
#include <stdio.h>

void pseudoSort(int arr[],int len){
    int a;
    int l=len;
    int k=0;
    while(len>1){
        for(int i=0;i<len/2;i++){
        a=arr[i];
        arr[i]=arr[len-i-1];
        arr[len-i-1]=a;
    }
    len/=2;
    }
    int lenght=l;
    while(l>1){
        l/=2;
        k=0;
        for(int i=l+1;i<2*l;i++){
            a=arr[i];
            arr[i]=arr[2*l-k];
            arr[2*l-k]=a;
            k++;
        }
    }
    arr[lenght]='\0';
    for(int i=0;arr[i]!='\0';i++){
        if(i){
            printf(",%d",arr[i]);
        }
        else{
            printf("%d",arr[i]);
        }
    }
    printf("\n");
}

int main(){
    int arr[]={1,2,3,4,5};  // 5,4,3,2,1    4,5,3,2,1   4,5,3,1,2   
    pseudoSort(arr,5);
    return 0;
}
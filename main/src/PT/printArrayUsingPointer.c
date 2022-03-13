#include <stdio.h>

int main(){
    int arr[]={10,20,30,40,50};
    int *p=arr;
    int a=sizeof(arr)/sizeof(arr[0]);
    while(a){
        printf("%d ",*p);
        p++;
        a--;
    }
    printf("\n");
    return 0;
}
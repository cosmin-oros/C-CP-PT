#include <stdio.h>

int searchA(int *arr,int size,int search){
    int *arrEnd=(arr+size-1);
    int k=1;
    while(arr<=arrEnd && *arr!=search){
        arr++;
        k++;
    }
    if(arr<=arrEnd){
        return k;
    }
    return -1;
}

void inputArray(int *arr,int size){
    int *arrEnd=(arr+size-1);
    while(arr<=arrEnd){
        scanf("%d",arr++);
    }
}

int main(){
    int arr[100],cap=100;
    int *p=arr;
    int n,search;
    printf("Enter the number of elements of the array: ");
    scanf("%d",&n);
    printf("\nEnter the elements of the array:\n");
    inputArray(arr,n);
    printf("Enter the element that you want to search:");
    scanf("%d",&search);
    int pos=searchA(arr,n,search);
    if(search==-1){
        printf("Couldn't find the element in the array\n");
    }
    else{
        printf("The element %d is found at position %d\n",search,pos);
    }
    return 0;
}
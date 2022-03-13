#include <stdio.h>

void printArray(int arr[],int size){
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

void rotateByOne(int arr[],int size){
    int last=arr[size-1];
    for(int i=size-1;i>0;i++){
        arr[i]=arr[i-1];
    }
    arr[0]=last;
}

int main(){
    int i,n;
    int arr[10],size=10;
    printf("Enter the elements of the array:\n");
    for(i=0;i<size;i++){
        scanf("%d",&arr[i]);
    }
    printf("Enter number of times to right rotate:\n");
    scanf("%d",&n);
    n=n%10; //10 - size of array
    printf("Array before rotation: ");
    printArray(arr,size);
    for(i=0;i<n;i++){
        rotateByOne(arr,size);
    }
    printf("\nArray after rotation:\n");
    printArray(arr,size);
    return 0;
}
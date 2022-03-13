#include <stdio.h>

void printUnique(int arr[], int n){
    for(int i=0;i<n;i++){
        int j;
        for(j=0;j<i;j++){
            if(arr[i]==arr[j]){
                break;
            }
        }
        if(i==j){
            printf("%d ",arr[i]);
        }
    }
    printf("\n");
}

int main(){
    int arr_size;
    printf("Enter the array size: ");
    scanf("%d",&arr_size);
    int arr[arr_size];
    printf("Enter %d elements of the array: \n",arr_size);
    for(int i=0;i<arr_size;i++){
        scanf("%d",&arr[i]);
    }
    printf("\nUnique elements of the array: \n");
    int n=sizeof(arr)/sizeof(arr[0]);
    printUnique(arr,n);
    return 0;
}
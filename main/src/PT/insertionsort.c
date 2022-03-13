#include <stdio.h>

#define SIZE 10

int arr[SIZE]={5,23,4,2,12,43,55,1,9,34};

void sort(int* arr){
    int temp;
    int j;
    for (int i = 1; i < SIZE; i++)
    {
        temp=arr[i];
        j=i-1;
        while ((temp<arr[j])&&(j>=0))
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=temp;
    }
    
}

// void read(){
//     printf("Enter %d elements: ",SIZE);
//     for (int i = 0; i < SIZE; i++)
//     {
//         scanf("%d",&arr[i]);
//     }
    
// }

int main(){
    // read();
    printf("Before sorting: ");
    for (int i = 0; i < SIZE; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\nAfter sorting: ");
    sort(arr);
    for (int i = 0; i < SIZE; i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}
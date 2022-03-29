#include <stdio.h>

#define SIZE 6

void quicksortRec(int* arr,int left,int right){
    int i,j;
    int x,aux;
    i=left; j=right;
    x=arr[(left+right)/2];
    do{
        while (arr[i]<x && i<right)
        {
            i++;
        }
        while (arr[j]>x && j>left)
        {
            j--;
        }
        if (i<=j)
        {
            aux=arr[i];
            arr[i]=arr[j];
            arr[j]=aux;
            i++;
            j--;
        }
    }while (i<=j);
    if (left<i)
    {
        quicksortRec(arr,left,j);
    }
    if (i<right)
    {
        quicksortRec(arr,i,right);
    }
}

int main(){
    int arr[SIZE] = {4,5,6,3,0,9};
    printf("Before sorting: ");
    for (int i = 0; i < SIZE; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
    quicksortRec(arr,0,SIZE);
    printf("After sorting: ");
    for (int i = 0; i < SIZE; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
    
    return 0;
}
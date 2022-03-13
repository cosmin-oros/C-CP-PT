#include <stdio.h>
#include <stdlib.h>

/*
. The rand() function declared in the <stdlib.h> interface and
explained in the GNU/Linux man pages can be used to generate
a random sequence of numbers and store them into a vector array.
Write a program to populate such an array of given size N and
sort the numbers using any of the two methods that are part of
Timsort.
*/



int* popArr(int N){
    int* randArr = calloc(N,sizeof(int));
    if (!randArr)
    {
        return NULL;
    }
    
    for (int i = 0; i < N; i++)
    {
        randArr[i]=rand()%(10-1+1)+1;
    }
    
    return randArr;
    free(randArr);
}

void printArr(int* randArr,int N){
    for (int i = 0; i < N; i++)
    {
        printf("%d ",randArr[i]);
    }
    
}

void insSort(int* arr,int SIZE){
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

int main(){
    int n;
    printf("Enter the size:");
    scanf("%d",&n);
    int* randArr = popArr(n);
    printf("\n");
    printArr(randArr,n);
    insSort(randArr,n);
    printf("\n");
    printArr(randArr,n);
    return 0;
}
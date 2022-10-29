#include <stdio.h>

#define N 8

void shellSort(int* arr){
    // sort elements at arbitrary intervals
    // bad interval 4 2 1  good interval 7 3 2 1

    // in this case the intervals are 7 3 and 1
    for (int interval = N-1; interval > 0; interval /= 2)
    {
        for (int i = interval; i < N; i++)
        {
            int temp = arr[i];
            int j;
            for (j = i; j >= interval && arr[j-interval] > temp; j -= interval)
            {
                arr[j] = arr[j-interval];
            }
            arr[j] = temp;
            
        }
        
    }
    
}

void printArray(int* arr){
    for (int i = 0; i < N; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
}

int main(){
    int arr[] = {9, 3, 4, 5, 1, 8, 3, 0};

    shellSort(arr);

    printf("Sorted Array: \n");
    printArray(arr);

    return 0;
}
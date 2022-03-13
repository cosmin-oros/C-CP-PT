#include <stdio.h>
#include <stdlib.h>

/*
1. Write a program to test the performance of the two sorting techniques, insertion sort and merge sort. Populate a vector array
with random numbers using the rand() function from <stdlib.h>.
Write two functions for sorting a local clone of the array called
insertion_sort () and merge_sort(). In C function parameters are
passed by locally cloning their values. Sort the array previously
populated with random numbers using the two techniques and
compare the swap counters for the two methods.
*/

#define N 10

void fillArray(int randomNrs[]){
    for (int i = 0; i < N; i++)
    {
        randomNrs[i]=rand()%10;
    }
}

void insertion_sort(int randomNrs[]){
    for (int i = 1; i < N; i++)
    {
        int key = randomNrs[i];
        int j=i-1;
        while (key<randomNrs[j]&&j>=0)
        {
            randomNrs[j+1]=randomNrs[j];
            j--;
        }
        randomNrs[j+1]=key;
        
    }
    
    
}

void merge_sort(int randomNrs[]){
    int p=0,r=N;
    int q=(p+r)/2;
    int k=0;
    int* L=malloc(q*sizeof(int));
    if (!L)
    {
        printf("Couldn't allocate mem\n");
        exit(-1);
    }
    int* R=malloc((N-q)*sizeof(int));
    if (!R)
    {
        printf("Couldn't allocate mem\n");
        exit(-1);
    }
    for (int i = 0; i < q; i++)
    {
        L[i]=randomNrs[i];
        printf("%d ",L[i]);
    }
    for (int i = q; i < r; i++)
    {
        R[k]=randomNrs[i];
        k++;
    }  
    int i=0,j=0;
    k=0;
    while (i<q && j<(N-q))
    {
        if (L[i] <= R[j]) {
            randomNrs[k] = L[i];
            i++;
        } else {
            randomNrs[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < q) {
        randomNrs[k] = L[i];
        i++;
        k++;
    }

    while (j < (N-q)) {
        randomNrs[k] = R[j];
        j++;
        k++;
    }
    free(L);
    free(R);

}

int main(){
    int randomNrs[N];
    fillArray(randomNrs);
    int clone[N];
    for (int i = 0; i < N; i++)
    {
        clone[i]=randomNrs[i];
    }
    insertion_sort(randomNrs);
    merge_sort(clone);
    printf("Insertion sort:");
    for (int i = 0; i < N; i++)
    {
        printf("%d ",randomNrs[i]);
    }
    printf("\n");
    printf("Merge sort:");
    for (int i = 0; i < N; i++)
    {
        printf("%d ",clone[i]);
    }
    printf("\n");
    
    return 0;
}
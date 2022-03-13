#include <stdio.h>
/*
A) Write a function int extractOdds(int v[ ], int n, int *arr[ ], int capacity which fills the array arr with addresses of odd elements from array v
 and returns the number of values filled in arr or -1, if the size would exceed the capacity.
*/

int extractOdds(int v[], int n, int *arr[],int capacity){
    int size=0;
    for(int i=0;i<n;i++){
        if(v[i]%2!=0){
            arr[size]=&v[i];
            size++;
        }
    }
    if(size<=capacity){
        return size;
    }
    else{
        return -1;
    }
}

int main(){
    int v[]={1,2,3,4,5,6,7,8,9,10,11};
    int n=11;
    int *arr[5];
    int capacity=5;
    printf("%d\n",extractOdds(v,n,arr,capacity));
    return 0;
}
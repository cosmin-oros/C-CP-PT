#include <stdio.h>
#include <stdlib.h>
 
int findPeak(int arr[],int j, int n)
{
    // if the array has only an element then it is the peak
    if (n==1)
    {
        return 0;
    }else if (j == 0)   //check the first element
    {
        if (arr[j]>=arr[j+1])
        {
            return j;
        }
        
    }else if (j == n-1) //check the last element
    {
        if (arr[j]>=arr[j-1])
        {
            return j;
        }
        
    }
 
    // check for every other element
    for (int i = j; i < n - 1; i++) {
 
        // check if the neighbors are smaller
        if (arr[i] >= arr[i - 1] && arr[i] >= arr[i + 1])
            return i;
    }
    return -1;
}
 
// Driver Code
int main()
{
    int arr[] = { 4,3,1,5,2,6 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int i = 0;
    int k = 0;

    while (i<n)
    {
        k = findPeak(arr,i,n);
        //if k is -1 it means that we couldn't find a peak in the range 0 -> n-2 (didn't check the last element)
        if(k != -1){
            printf("The peak of the Array is: %d at index %d\n",arr[k],k);
            i = k;
        }
        else{
            i = n-2;
        }
        i++;

    }
    return 0;
}
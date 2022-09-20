#include <iostream>

using namespace std;

/*
    Given a sorted array, and an element x to be 
    searched, find position of x in the array.

    Input:  arr[] = {10, 20, 40, 45, 55}
            x = 45
    Output: Element found at index 3
*/

int binarySearch(int arr[], int l, int r, int x){
    if (r >= l)
    {
        int mid = l + (r - l)/2;
  
        if (arr[mid] == x){
            return mid;
        }
  
        if (arr[mid] > x){
            return binarySearch(arr, l, mid-1, x);
        }
  
        return binarySearch(arr, mid+1, r, x);
    }
  
    return -1;
}

int exponentialSearch(int arr[], int n, int x){
    // If x is present at first location itself
    if (arr[0] == x){
        return 0;
    }
  
    // Find range for binary search by
    // repeated doubling
    int i = 1;

    while (i < n && arr[i] <= x){
        i *= 2;
    }
  
    //  Call binary search for the found range.
    return binarySearch(arr, i/2, min(i, n-1), x);
}

int main(){ 
    int arr[] = {2, 3, 4, 10, 40};
    int n = sizeof(arr)/ sizeof(arr[0]);
    int x = 10;

    int result = exponentialSearch(arr, n, x);

    (result == -1) ? cout << "Element is not present in array" << endl : cout << "Element is present at index " << result << endl;

    return 0;
}
#include <iostream>

using namespace std;

// func to get the max in an array
int dacMax(int* arr, int l, int r){
    int max;
    // only one element in the array case
    if (r-1 == 0)
    {
        return arr[l];
    }

    if (l >= r-2)
    {
        if (arr[l] > arr[l+1])
        {
            return arr[l];
        }else{
            return arr[l+1];
        }
        
    }

    max = dacMax(arr, l+1, r);

    if (arr[l] > max)
    {
        return arr[l];
    }else{
        return max;
    }
    
}

int dacMin(int* arr, int l, int r){
    int min;
    // only one element in the array case
    if (r-1 == 0)
    {
        return arr[l];
    }

    if (l >= r-2)
    {
        if (arr[l] < arr[l+1])
        {
            return arr[l];
        }else{
            return arr[l+1];
        }
        
    }

    min = dacMin(arr, l+1, r);

    if (arr[l] < min)
    {
        return arr[l];
    }else{
        return min;
    }
}

int main(){
    int min, max;

    int arr[9] = {1, 4 , 5, 2, 9, 3, 12, 3, 5};

    // recursive divide and conquer 
    max = dacMax(arr, 0, 9);
    min = dacMin(arr, 0, 9);

    cout << "The max in the array is: " << max << endl;
    cout << "The min in the array is: " << min << endl;

    return 0;
}
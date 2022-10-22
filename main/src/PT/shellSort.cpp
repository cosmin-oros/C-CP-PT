#include <iostream>

using namespace std;

#define N 5

// function for sorting the array using shellsort
void shellSort(int* arr){
    // start with a big gap then reduce the gap
    for (int gap = N/2; gap > 0; gap--)
    {
        for (int i = gap; i < N; i++)
        {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j-gap] > temp; j -= gap)
            {
                arr[j] = arr[j-gap];
            }
            arr[j] = temp;
            
        }
        
    }
    
}

// function for printing the array
void printArray(int* arr){
    for (int i = 0; i < N; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    
}

int main(){
    int arr[N] = {12, 2, 13, 5, 9};

    cout << "Arr before sorting: " << endl;
    printArray(arr);

    shellSort(arr);

    cout << "Arr after sorting: " << endl;
    printArray(arr);

    return 0;
}
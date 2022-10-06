#include <iostream>
#include <algorithm>

using namespace std;

void printArray(int arr[], int arrSize){
    for (int i = 0; i < arrSize; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    
}

int main(){
    int arr[] = {4, 3, 2, 5, 1, 9, 0, 4};
    int arrSize = sizeof(arr) / sizeof(arr[0]);
    int element = 2;

    cout << "Initial array: ";
    printArray(arr, arrSize);

    sort(arr, arr+arrSize);

    if (binary_search(arr, arr+arrSize, element))
    {
        cout << "Element " << element << " found in the array" << endl;  
    }else{
        cout << "Element " << element << " not found in the array" << endl;  
    }

    return 0;
}
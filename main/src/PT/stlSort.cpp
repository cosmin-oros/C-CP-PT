#include <iostream>
#include <algorithm>

using namespace std;

void printArray(int arr[], int size){
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
    int arr[] = {4, 1, 5, 2, 2, 9, 10, 12, 1};
    int arrSize = sizeof(arr) / sizeof(arr[0]);

    cout << "Before sorting: " << endl;
    printArray(arr, arrSize);

    sort(arr, arr + arrSize);

    cout << "After sorting: " << endl;
    printArray(arr, arrSize);

    return 0;
}
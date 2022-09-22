#include <iostream>

using namespace std;

/*
    Given an array, write a program to generate a random permutation of array elements. 
    This question is also asked as “shuffle a deck of cards” or “randomize a given array”.
    Here shuffle means that every permutation of array element should be equally likely. 
*/

void swap (int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void printArray(int* arr, int n){
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    
}

void randomize(int* arr, int n){
    // use different seed value so we get a different value each time
    srand(time(NULL));

    for (int i = n-1; i > 0; i--)
    {
        int j = rand() % (i+1);

        swap(&arr[i], &arr[j]);
    }

}

int main(){
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    randomize (arr, n);
    
    printArray(arr, n);

    return 0;
}
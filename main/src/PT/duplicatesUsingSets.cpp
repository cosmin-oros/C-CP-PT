#include <iostream>
#include <unordered_set>

using namespace std;

int* generateRandomArr(){
    int size = rand() % 1000 + 1;
    int* arr = (int*)malloc(size*sizeof(int));

    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % 100 + 1;
    }

    // make the last element 0 so that it's easier to check for the end
    arr[size-1] = 0;

    return arr;
}

void printDuplicates(int* arr){
    // unordered sets for checking and storing dups
    unordered_set<int> intSet;
    unordered_set<int> dups;

    for (int i = 0; arr[i]; i++)
    {
        // if the element is in the intSet then insert it in the dups set else insert it into the intSet
        if (intSet.find(arr[i]) == intSet.end())
        {
            intSet.insert(arr[i]);
        }else{
            dups.insert(arr[i]);
        }
        
    }

    // iterator for printing the dups
    unordered_set<int> :: iterator it;

    cout << "Duplicates: ";
    for (it = dups.begin(); it != dups.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
    
    
}

int main(){
    int* arr = generateRandomArr();
    
    // for (int i = 0; arr[i]; i++)
    // {
    //     cout << arr[i] << " ";
    // }
    
    printDuplicates(arr);

    return 0;
}
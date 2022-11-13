#include <iostream>
#include <algorithm>
#include <vector>

int main(){
    // Initializing vector with array values
    int arr[] = {5, 10, 15, 20, 20, 23, 42, 45};
    int n = sizeof(arr)/sizeof(arr[0]);
    std::vector<int> vect(arr, arr+n);
 
    std::cout << "Given Vector is:\n";
    for (int i = 0; i < n; i++){
        std::cout << vect[i] << " ";
    }
 
    // modifies vector to its next permutation order
    next_permutation(vect.begin(), vect.end());
    std::cout << "\nVector after performing next permutation:\n";
    for (int i = 0; i < n; i++){
        std::cout << vect[i] << " ";
    }
 
    prev_permutation(vect.begin(), vect.end());
    std::cout << "\nVector after performing prev permutation:\n";
    for (int i = 0; i < n; i++){
        std::cout << vect[i] << " ";
    }

    std::cout << "\nDistance between first to max element: ";
    std::cout << distance(vect.begin(), max_element(vect.begin(), vect.end()));
 
    return 0;
}
#include <iostream>
#include <numeric>
#include <algorithm>
#include <vector>

#define N 6

int main(){
    int arr[] = {10, 123, 14, 9, 123, 5};
    std::vector<int> v(arr, arr+N);

    std::cout << "The vector: ";
    for (int i = 0; i < N; i++)
    {
        std::cout << v[i] << " ";
    }
    std::cout << "\n";

    // sorting the vector
    sort(v.begin(), v.end());

    std::cout << "The vector after sorting: ";
    for (int i = 0; i < N; i++)
    {
        std::cout << v[i] << " ";
    }
    std::cout << "\n";
    
    // sorting the vector descending
    sort(v.begin(), v.end(), std::greater<int>());

    std::cout << "The vector after sorting: ";
    for (int i = 0; i < N; i++)
    {
        std::cout << v[i] << " ";
    }
    std::cout << "\n";

    // reversing the vector
    reverse(v.begin(), v.end());

    std::cout << "The vector after reversing: ";
    for (int i = 0; i < N; i++)
    {
        std::cout << v[i] << " ";
    }
    std::cout << "\n";

    std::cout << "The max element in the vector is: " << *max_element(v.begin(), v.end()); 
    std::cout << "The max element in the vector is: " << *min_element(v.begin(), v.end()); 
    std::cout << "The sum of the vector: " << accumulate(v.begin(), v.end(), 0); 

    return 0;
}
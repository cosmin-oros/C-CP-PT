#include<iostream>
#include<array> 
#include<tuple>

int main(){
    std::array<int,6> arr = {1, 2, 3, 4, 5, 6};
 
    std::cout << "The array elements are (using at()) : ";
    for (int i=0; i<6; i++){
        std::cout << arr.at(i) << " ";
    }
    std::cout << "\n";
 
    // Printing array elements using get()
    std::cout << "The array elements are (using get()) : ";
    std::cout << std::get<0>(arr) << " " << std::get<1>(arr) << " ";
    std::cout << std::get<2>(arr) << " " << std::get<3>(arr) << " ";
    std::cout << std::get<4>(arr) << " " << std::get<5>(arr) << " ";
    std::cout << "\n";
 
    // Printing array elements using operator[]
    std::cout << "The array elements are (using operator[]) : ";
    for (int i=0; i < 6; i++){
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";

    return 0;
}
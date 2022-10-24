#include <iostream>
#include <vector>

#define N 3

int main(){
    std::vector<std::vector<int>> v = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    }; 

    // remove the last element of the third and second row
    v[2].pop_back();
    v[1].pop_back();

    for (int i = 0; i < N; i++)
    {
        for (auto it = v[i].begin(); it != v[i].end(); it++)
        {
            std::cout << *it << " ";
        }
        std::cout << "\n";
        
    }

    for (int i = 0; i < N; i++)
    {
        for (auto it = v[i].rbegin(); it != v[i].rend(); it++)
        {
            std::cout << *it << " ";
        }
        std::cout << "\n";
        
    }
    
    std::cout << "\nSize: " << v.size();
    std::cout << "\nCapacity: " << v.capacity();
    std::cout << "\nMax Size: " << v.max_size();

    v.resize(4);
    std::cout << "\nSize: " << v.size();
    std::cout << "\n";

    v.shrink_to_fit();
    for (int i = 0; i < N; i++)
    {
        for (auto it = v[i].rbegin(); it != v[i].rend(); it++)
        {
            std::cout << *it << " ";
        }
        std::cout << "\n";
        
    }

    return 0;
}
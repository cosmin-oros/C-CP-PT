#include <iostream>

#define N 8

int compare(const void* ap, const void* bp)
{
    // Typecasting
    const int* a = (int*)ap;
    const int* b = (int*)bp;
  
    if (*a < *b){
        return -1;
    }else if (*a > *b){
        return 1;
    }else{
        return 0;
    }
}

int main(){
    int arr[N] = { 1, 2, 3, 4, 5, 6, 7, 8 };
    int elem1 = 4;
    int elem2 = 9;

    int* p1 = (int*)std::bsearch(&elem1, arr, N, sizeof(arr[0]), compare);

    if (p1){
        std::cout << elem1 << " found at position " << (p1 - arr) << '\n';
    }
    else{
        std::cout << elem1 << " not found\n";
    }

    int* p2 = (int*)std::bsearch(&elem2, arr, N, sizeof(arr[0]), compare);

    if (p2){
        std::cout << elem2 << " found at position " << (p1 - arr) << '\n';
    }
    else{
        std::cout << elem2 << " not found\n";
    }

    return 0;
}
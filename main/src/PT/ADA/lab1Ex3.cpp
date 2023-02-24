#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <chrono>

/*
    Implement the operation ExistTriplet which, given the arrays A, B and C and a value V, 
    determines if there exists a triplet of numbers (a, b, c) having the sum V, where a is from A, b from B and c from C.
*/

bool existTriplet(std::vector<int> A, std::vector<int> B, std::vector<int> C, int V) {
    // sort the 3 arrays
    std::sort(A.begin(), A.end());
    std::sort(B.begin(), B.end());
    std::sort(C.begin(), C.end());

    // we use two pointers to iterate through B and C, the pointer j start at the start of B and k starts at the end of C
    for (int i = 0; i < A.size(); i++) {
        int j = 0, k = C.size() - 1;

        while (j < B.size() && k >= 0) {
            int sum = A[i] + B[j] + C[k];

            if (sum == V) {
                return true;
            } else if (sum < V) {
                j++;
            } else {
                k--;
            }
        }
    }

    return false;
    
}

int main() {
    
    int sizeA;
    int sizeB;
    int sizeC;
    int V;
    std::ifstream inputFile;

    // open the file with the ints and check if it was opened
    inputFile.open("1Kint_1.txt");
    if (!inputFile)
    {
        std::cout << "Couldn't open the file";
        return -1;
    }
    
    // read the size of array A
    inputFile >> sizeA;

    // read the values for the array A
    std::vector<int> A (sizeA);
    for (int i = 0; i < sizeA; i++)
    {
        inputFile >> A[i];
    }

    // read the size of array B
    inputFile >> sizeB;

    // read the values for the array B
    std::vector<int> B (sizeB);
    for (int i = 0; i < sizeB; i++)
    {
        inputFile >> B[i];
    }

    // read the size of array C
    inputFile >> sizeC;

    // read the values for the array C
    std::vector<int> C (sizeC);
    for (int i = 0; i < sizeC; i++)
    {
        inputFile >> C[i];
    }

    // close the file
    inputFile.close();

    // measure the runtime for the function existTriplet
    auto start = std::chrono::high_resolution_clock::now();
    bool triplet = existTriplet(A, B, C, V);
    auto end = std::chrono::high_resolution_clock::now();

    if (triplet)
    {
        std::cout << "There exists a triplet of numbers (a, b, c)" << std::endl;
    } else {
        std::cout << "There doesn't exist a triplet of numbers (a, b, c)" << std::endl;
    }

    double time_taken = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();

    std::cout << "Runtime : " << time_taken << " microseconds" << std::endl;

    return 0;
}
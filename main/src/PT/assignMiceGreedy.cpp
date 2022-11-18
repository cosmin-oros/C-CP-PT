#include <iostream>
#include <algorithm>

#define N 3

int assignHole(int mices[], int holes[], int n, int m) {
     
    // Base Condition
    // No. of mice and holes should be same
    if (n != m) {
        return -1;
    }
     
    // Sort the arrays
    std::sort(mices, mices + n);
    std::sort(holes, holes + m);
     
    // Finding max difference between
    // ith mice and hole
    int max = 0;
    for(int i = 0; i < n; ++i)
    {
        if (max < abs(mices[i] - holes[i])){
            max = abs(mices[i] - holes[i]);
        }
    }

    return max;
}

int main(){
     
    // Position of mice
    int mices[] = { 4, -4, 2 };
   
    // Position of holes
    int holes[] = { 4, 0, 5 };
   
    // The required answer is returned
    // from the function
    int minTime = assignHole(mices, holes, N, N);
   
    std::cout << "The last mouse gets into the hole in time:" << minTime << "\n";
   
    return 0;
}
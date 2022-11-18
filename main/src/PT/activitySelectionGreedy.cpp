#include <iostream>

#define N 6

void printMaxActivities(int s[], int f[], int n){
    int i, j;
 
    std::cout << "Following activities are selected\n";
 
    // The first activity always gets selected
    i = 0;
    std::cout << i << " ";
 
    // Consider rest of the activities
    for (j = 1; j < n; j++) {
        // If this activity has start time greater than or
        // equal to the finish time of previously selected
        // activity, then select it
        if (s[j] >= f[i]) {
            std::cout << j << " ";
            i = j;
        }
    }
}

int main() {
    int s[] = { 1, 3, 0, 5, 8, 5 };
    int f[] = { 2, 4, 6, 7, 9, 9 };
 
    printMaxActivities(s, f, N);
    return 0;
}
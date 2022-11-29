#include <iostream>
#include <cstring>
#include <algorithm>

struct suffix {
    int index;
    char *suff;
};
  
int cmp(struct suffix a, struct suffix b) {
    return strcmp(a.suff, b.suff) < 0? 1 : 0;
}
  
int* buildSuffixArray(char *txt, int n) {
    struct suffix* suffixes = new struct suffix [n];
  
    // Store suffixes and their indexes in an array of structures.
    // The structure is needed to sort the suffixes alphabetically
    // and maintain their old indexes while sorting
    for (int i = 0; i < n; i++) {
        suffixes[i].index = i;
        suffixes[i].suff = (txt+i);
    }
  
    // Sort the suffixes using the comparison function
    // defined above.
    std::sort(suffixes, suffixes+n, cmp);
  
    // Store indexes of all sorted suffixes in the suffix array
    int *suffixArr = new int[n];
    for (int i = 0; i < n; i++)
        suffixArr[i] = suffixes[i].index;
  
    // Return the suffix array
    return  suffixArr;
}
  
// A utility function to print an array of given size
void printArr(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}

int main() {
    char txt[] = "banana";
    int n = strlen(txt);

    int *suffixArr = buildSuffixArray(txt,  n);
    std::cout << "Following is suffix array for " << txt << "\n";
    
    printArr(suffixArr, n);
    
    return 0;
}
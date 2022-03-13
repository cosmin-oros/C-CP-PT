#include <stdio.h>

int maxSequence(const int* array, size_t n) {
    int maxSoFar=0;
    int maxEndingHere=0;
    int size = (int) n;
    for (int i = 0; i < size; i++){
        maxEndingHere+=array[i];
        if (maxEndingHere<0)
        {
            maxEndingHere=0;
        }
        if (maxSoFar<maxEndingHere)
        {
            maxSoFar=maxEndingHere;
        }
        
                
    }
    return maxSoFar;
    
}

int main(){
    int array[] = {1,-3,2,-4,5};
    int size = sizeof(array);
    printf("%d\n",maxSequence(array,size));
    return 0;
}
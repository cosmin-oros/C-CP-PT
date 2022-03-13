#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, max, newSize;
    int *ptr;

    // Input maximum elements of array
    printf("Enter total number of elements: ");
    scanf("%d", &max);
    
    // Allocate memory for 'max' integer elements using calloc
    ptr = (int *) calloc(max, sizeof(int));
    
    // If memory not allocated
    if(ptr == NULL)
    {
        printf("Memory is not created!!!");
        exit(0); // Exit from the program
    }
    
    // Input elements from user
    printf("Enter %d elements: \n", max);
    for (i = 0; i < max; i++)
        scanf("%d", (ptr + i));

    // Reallocate memory 
    printf("\nEnter new size of the array: ");
    scanf("%d", &newSize);
    ptr = (int *) realloc(ptr, (newSize * sizeof(int)));

    
    // Input elements in newly allocated memory
    printf("\nEnter %d elements: \n", (newSize - max));
    for (i = max; i < newSize; i++)
        scanf("%d", (ptr + i));
    
    // Print all elements 
    printf("\nArray elements are:\n");
    for (i = 0; i < newSize; i++)
        printf("%d ", *(ptr + i));
    
    // Release allocated memory
    free(ptr);
    
    return 0;
}
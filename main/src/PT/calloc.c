#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, max;
    int *ptr;

    // Input maximum elements of array
    printf("Enter total number of elements: ");
    scanf("%d", &max);
    
    // Allocate memory for 'max' integer elements 
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
    
    // Print all elements 
    printf("\nArray elements are:\n");
    for (i = 0; i < max; i++)
        printf("%d ", *(ptr + i));
    
    // Release allocated memory
    free(ptr);
    
    return 0;
}
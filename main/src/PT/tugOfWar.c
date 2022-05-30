#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

// function that tries every possible solution by calling itself recursively
void TOWUtil(int* arr, int n, bool* curr_elements, int no_of_selected_elements,
             bool* soln, int* min_diff, int sum, int curr_sum, int curr_position){
                 // checks whether the it is going out of bound
    if (curr_position == n){
        return;
    }

    // checks that the numbers of elements left are not less than the
    // number of elements required to form the solution
    if ((n/2 - no_of_selected_elements) > (n - curr_position)){
        return;
    }

    // consider the cases when current element is not included in the solution
    TOWUtil(arr, n, curr_elements, no_of_selected_elements, 
            soln, min_diff, sum, curr_sum, curr_position+1);
    
    // add the current element to the solution
    no_of_selected_elements++;
    curr_sum = curr_sum + arr[curr_position];
    curr_elements[curr_position] = true;

    // checks if a solution is formed
    if (no_of_selected_elements == n/2)
    {
        // checks if the solution formed is better than the best solution so far
        if (abs(sum/2 - curr_sum) < *min_diff)
        {
            *min_diff = abs(sum/2 - curr_sum);
            for (int i = 0; i<n; i++)
                soln[i] = curr_elements[i];
        }
    }
    else
    {
        // consider the cases where current element is included in the solution
        TOWUtil(arr, n, curr_elements, no_of_selected_elements, soln,
                  min_diff, sum, curr_sum, curr_position+1);
    }

    // removes current element before returning to the caller of this function
    curr_elements[curr_position] = false;
}

void tugOfWar(int* arr, int n){
    // the boolean array that contains the inclusion and exclusion of an element
    // in current set. The number excluded automatically form the other set
    bool* curr_elements = malloc(n*sizeof(bool));
    if (!curr_elements)
    {
        printf("Couldn't allocate mem\n");
        exit(1);
    }
    // The inclusion/exclusion array for final solution
    bool* soln = malloc(n*sizeof(bool));
    if (!soln)
    {
        printf("Couldn't allocate mem\n");
        exit(1);
    }

    int min_diff = INT_MAX;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        curr_elements[i] = false;
        soln[i] = false;
    }

    // Find the solution using recursive function TOWUtil()
    TOWUtil(arr, n, curr_elements, 0, soln, &min_diff, sum, 0, 0);

    // Print the solution
    printf("The first subset is: ");
    for (int i = 0; i < n; i++)
    {
        if (soln[i] == true)
        {
            printf("%d ",arr[i]);
        }
        
    }
    printf("\nThe second subset is: ");
    for (int i = 0; i < n; i++)
    {
        if (soln[i] == false)
        {
            printf("%d ",arr[i]);
        }
        
    }
    
}

int main()
{
    int arr[] = {23, 45, -34, 12, 0, 98, -99, 4, 189, -1, 4};
    int n = sizeof(arr)/sizeof(arr[0]);
    tugOfWar(arr, n);
    return 0;
}
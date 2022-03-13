#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
Write a program to test the performance of the binary search
technique. Populate a vector array of 2
N elements with random
numbers using the rand() function from <stdlib.h>. N is given as
input, with N=10 being a good starting point. 2
10 = 1024. Search
for the presence of a given number X in the sequence. Before
sorting you can use linear search, reading the array element by
element from 0 to N-1 or from N-1 down to 0. Sort the array and
search again using binary search. Count the number of steps
during each search attempt. Compare the final counters and
display the results: was the given X number found? Repeat the
steps for different values of N
*/

int* popArray(int n){
    int size=1; //pow
    while (n)
    {
        size*=2;
        n--;
    }
    
    int* randArr = calloc(size,sizeof(int));
    if (!randArr)
    {
        return NULL;
    }
    for (int i = 0; i < size; i++)
    {
        randArr[i]=rand()%(20+1-1)+1;   //%(max+1-min)+min
    }
    return randArr;
    free(randArr);
}

int linearSearch(int n,int* randArr,int x){
    for (int i = 0; i < n; i++)
    {
        if (randArr[i]==x)
        {
            return 1;
        }
        
    }
    return 0;
    
}

void insertion_sort(int randomNrs[]){
    for (int i = 1; randomNrs[i]!=0; i++)
    {
        int key = randomNrs[i];
        int j=i-1;
        while (key<randomNrs[j]&&j>=0)
        {
            randomNrs[j+1]=randomNrs[j];
            j--;
        }
        randomNrs[j+1]=key;
        
    }
    
}

int binarySearch(int array[], int x, int low, int high) {
  // Repeat until the pointers low and high meet each other
  while (low <= high) {
    int mid = low + (high - low) / 2;

    if (array[mid] == x)
      return mid;

    if (array[mid] < x)
      low = mid + 1;

    else
      high = mid - 1;
  }

  return -1;
}


int main(){
    int N,x;
    printf("Enter the N value: ");
    scanf("%d",&N);
    int* randArray=popArray(N);
    int size = 1;
    int n = N;
    while (n)
    {
        size*=2;
        n--;
    }
    
    if (randArray)
    {
        printf("\n");
        for (int i = 0; randArray[i]!=0; i++)
        {
            printf("%d ",randArray[i]);
        }
        
        printf("\nEnter the value to be searched: ");
        scanf("%d",&x);
        if (linearSearch(size,randArray,x))     //
        {
            printf("\nfound\n");
        }
        else{
            printf("\nnot found\n");    // <-- doesn't work prop
        }
        insertion_sort(randArray);
        printf("\nSorted array: ");
        for (int i = 0; randArray[i]; i++)
        {
            printf("%d ",randArray[i]);
        }
        if (binarySearch(randArray,x,0,size-1)!=-1)        //
        {
            printf("\nfound\n");
        }
        else{
            printf("\nnot found\n");
        }
        
        
    }
    else{
        printf("\nCouldn't allocate mem\n");
    }
    
    return 0;
}